# %%
# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2021/1/8 17:43
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: Sentiment_Analysis_on_Movie_Reviews.py
# @Reference:

from datetime import timedelta
import torch
import torch.nn as nn
import pandas as pd
import numpy as np

train_csv = pd.read_csv("./train.tsv", sep='\t')
test_csv = pd.read_csv("./test.tsv", sep='\t')
train_csv.head(50)
# %%
test_csv.head()
# %%

# 切分出一些验证集，分层抽样
from sklearn.model_selection import StratifiedShuffleSplit

splt = StratifiedShuffleSplit(n_splits=1, test_size=0.2, random_state=1)
for train_idx, valid_idx in splt.split(train_csv, train_csv['Sentiment']):
    train_part = train_csv.loc[train_idx]
    valid_part = train_csv.loc[valid_idx]

y_train = train_part['Sentiment']
y_valid = valid_part['Sentiment']
X_train = train_part['Phrase']
X_valid = valid_part['Phrase']

X_test = test_csv['Phrase']
y_test = [0] * len(X_test)  # 测试集没有标签，这么处理方便代码处理
y_test = torch.LongTensor(y_test)  # 转成tensor

# %%

PAD, CLS = '[PAD]', '[CLS]'
max_seq_len = 64
bert_hidden = 768
num_classes = 5
learning_rate = 1e-5
decay = 0.01
num_epochs = 5
early_stop_time = 2000
batch_size = 32
save_path = "./best_model.ckpt"
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
# %%

from transformers import AutoTokenizer, BertForSequenceClassification

tokenizer = AutoTokenizer.from_pretrained("./bert-base-uncased")

pretrain_model = BertForSequenceClassification.from_pretrained("./bert-base-uncased", num_labels=num_classes)


def load_dataset(texts, labels):
    contents = []
    for t, label in zip(texts, labels):
        token = tokenizer.tokenize(t)
        token = [CLS] + token
        # ['[CLS]', 'subject', ':', 'cell', 'phones', 'coming', 'soon', '<', 'html', '>', ...]
        seq_len = len(token)
        mask = []
        token_ids = tokenizer.convert_tokens_to_ids(token)
        # [101, 3395, 1024, 3526, 11640, 2746, 2574, 1026, 16129, 。。。]
        if len(token) < max_seq_len:
            mask = [1] * len(token) + [0] * (max_seq_len - len(token))
            token_ids = token_ids + [0] * (max_seq_len - len(token))
        else:
            mask = [1] * max_seq_len
            token_ids = token_ids[:max_seq_len]
            seq_len = max_seq_len
        y = [0] * num_classes
        y[label] = 1
        contents.append((token_ids, y, seq_len, mask))
    return contents


load_dataset(X_train, y_train)


# %%

def build_iter(datasets, batch_size, device):
    iter = datasetIter(datasets, batch_size, device)
    return iter


class datasetIter():
    def __init__(self, datasets, batch_size, device):
        self.datasets = datasets
        self.idx = 0
        self.device = device
        self.batch_size = batch_size
        self.batches = len(datasets) // batch_size
        self.residues = False
        if len(datasets) % batch_size != 0:
            self.residues = True

    def __next__(self):
        if self.residues and self.idx == self.batches:
            batch_data = self.datasets[self.idx * self.batch_size: len(self.datasets)]
            self.idx += 1
            batch_data = self._to_tensor(batch_data)
            return batch_data
        elif self.idx > self.batches:
            self.idx = 0
            raise StopIteration
        else:
            batch_data = self.datasets[self.idx * self.batch_size: (self.idx + 1) * self.batch_size]
            self.idx += 1
            batch_data = self._to_tensor(batch_data)
            return batch_data

    def _to_tensor(self, datasets):
        x = torch.LongTensor([item[0] for item in datasets]).to(self.device)
        y = torch.FloatTensor([item[1] for item in datasets]).to(self.device)
        seq_len = torch.LongTensor([item[2] for item in datasets]).to(self.device)
        mask = torch.LongTensor([item[3] for item in datasets]).to(self.device)
        return (x, seq_len, mask), y

    def __iter__(self):
        return self

    def __len__(self):
        if self.residues:
            return self.batches + 1
        else:
            return self.batches


# %%


class myModel(nn.Module):
    def __init__(self):
        super(myModel, self).__init__()
        self.pretrain_model = pretrain_model
        for param in self.pretrain_model.parameters():
            param.requires_grad = True

    def forward(self, x):
        context = x[0]
        mask = x[2]
        out = self.pretrain_model(context, attention_mask=mask)
        out = torch.softmax(out.logits, 1)
        return out


# %%

import time
import torch.nn.functional as F

from sklearn import metrics
from transformers.optimization import AdamW


def get_time_dif(starttime):
    # calculate used time
    endtime = time.time()
    return timedelta(seconds=int(round(endtime - starttime)))


def evaluate(model, dev_iter):
    model.eval()
    loss_total = 0
    pred_all = np.array([], dtype=int)
    labels_all = np.array([], dtype=int)
    with torch.no_grad():
        for X, y in dev_iter:
            outputs = model(X)
            # y = y.unsqueeze(1)
            loss = F.binary_cross_entropy(outputs, y)
            loss_total += loss
            truelabels = torch.max(y.data, 1)[1].cpu()
            pred = torch.max(outputs, 1)[1].cpu().numpy()
            labels_all = np.append(labels_all, truelabels)
            pred_all = np.append(pred_all, pred)
    acc = metrics.accuracy_score(labels_all, pred_all)
    return acc, loss_total / len(dev_iter)


def test(model, test_iter):
    model.load_state_dict(torch.load(save_path))
    model.eval()
    pred_all = np.array([], dtype=int)
    with torch.no_grad():
        for X, y in test_iter:
            outputs = model(X)
            pred = torch.max(outputs, 1)[1].cpu().numpy()
            pred_all = np.append(pred_all, pred)
    id = test_csv['PhraseId']
    output = pd.DataFrame({'PhraseId': id, 'Sentiment': pred_all})
    output.to_csv("submission_bert.csv", index=False)


def train(model, train_iter, dev_iter, test_iter):
    starttime = time.time()
    model.train()
    optimizer = AdamW(model.parameters(), lr=learning_rate, weight_decay=decay)
    total_batch = 0
    dev_best_loss = float("inf")
    last_improve = 0
    no_improve_flag = False
    model.train()
    for epoch in range(num_epochs):
        print("Epoch {}/{}".format(epoch + 1, num_epochs))
        for i, (X, y) in enumerate(train_iter):
            outputs = model(X)  # batch_size * num_classes
            model.zero_grad()
            loss = F.binary_cross_entropy(outputs, y)
            loss.backward()
            optimizer.step()
            if total_batch % 100 == 0:
                truelabels = torch.max(y.data, 1)[1].cpu()
                pred = torch.max(outputs, 1)[1].cpu()
                train_acc = metrics.accuracy_score(truelabels, pred)
                dev_acc, dev_loss = evaluate(model, dev_iter)
                if dev_loss < dev_best_loss:
                    dev_best_loss = dev_loss
                    torch.save(model.state_dict(), save_path)
                    improve = '*'
                    last_improve = total_batch
                else:
                    improve = ' '
                time_dif = get_time_dif(starttime)
                # 打印训练信息，id : >右对齐，n 宽度，.3 小数位数
                msg = 'Iter:{0:>6}, Train Loss:{1:>5.2}, Train Acc:{2:>6.2}, Val Loss:{3:>5.2}, val Acc :{4:>6.2%}, Time:{5} {6}'
                print(msg.format(total_batch, loss.item(), train_acc, dev_loss, dev_acc, time_dif, improve))
                model.train()
            total_batch += 1
            if total_batch - last_improve > early_stop_time:
                print("no improve after {} times, stop!".format(early_stop_time))
                no_improve_flag = True
                break
        if no_improve_flag:
            break
    test(model, test_iter)


# %%
np.random.seed(520)
torch.manual_seed(520)
torch.cuda.manual_seed_all(520)
torch.backends.cudnn.deterministic = True

train_data = load_dataset(X_train, y_train)
valid_data = load_dataset(X_valid, y_valid)
test_data = load_dataset(X_test, y_test)
train_iter = build_iter(train_data, batch_size, device)
valid_iter = build_iter(valid_data, batch_size, device)
test_iter = build_iter(test_data, batch_size, device)

model = myModel().to(device)
train(model, train_iter, valid_iter, test_iter)
# %%
