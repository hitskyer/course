#%%
import pandas as pd
import matplotlib.pyplot as plt

plt.rcParams['figure.facecolor']=(1,1,1,1) # pycharm 绘图白底，看得清坐标
from sklearn.preprocessing import OneHotEncoder

train = pd.read_csv("./train_set.csv")
test = pd.read_csv("./test_set.csv")

#%%
train['default_']=0
train['default_'][train['default']=='yes'] = 1
train['housing_']=0
train['housing_'][train['housing']=='yes'] = 1
train['loan_']=0
train['loan_'][train['loan']=='yes'] = 1

test['default_']=0
test['default_'][test['default']=='yes'] = 1
test['housing_']=0
test['housing_'][test['housing']=='yes'] = 1
test['loan_']=0
test['loan_'][test['loan']=='yes'] = 1

#%%
X_train = train.drop(['ID','default','housing','loan'], axis=1)
X_test = test.drop(['ID','default','housing','loan'], axis=1)

def num_cat_splitor(X_train):
    s = (X_train.dtypes == 'object')
    object_cols = list(s[s].index)
    num_cols = list(set(X_train.columns) - set(object_cols))
    return num_cols, object_cols

num_cols, object_cols = num_cat_splitor(X_train)
num_cols
object_cols

enc = OneHotEncoder(sparse=False, handle_unknown='ignore')
X_train_cat = enc.fit_transform(X_train[object_cols])
# X_test_cat = enc.transform(X_test[object_cols])
X_train_num = X_train[num_cols]
# X_test_num = X_test[num_cols]

#%%

name = enc.get_feature_names(object_cols)
print(name)
X_train_cat = pd.DataFrame(X_train_cat)
X_train_cat.columns = name
X_train = pd.concat([X_train_cat, X_train_num], axis=1)

X_train.head()
X_train.to_csv('train_cmm.csv')
#%%

# 将训练集拆分一些出来做验证, 分层抽样
from sklearn.model_selection import StratifiedShuffleSplit
splt = StratifiedShuffleSplit(n_splits=1, test_size=0.2, random_state=1)
for train_idx, vaild_idx in splt.split(X_train, X_train['y']):
    train_part = X_train.loc[train_idx]
    valid_part = X_train.loc[vaild_idx]

train_part_y = train_part['y']
valid_part_y = valid_part['y']
train_part = train_part.drop(['y'], axis=1)
valid_part = valid_part.drop(['y'], axis=1)


#%%

from sklearn.ensemble import GradientBoostingClassifier
from sklearn.metrics import roc_auc_score

model = GradientBoostingClassifier(learning_rate=0.1, n_estimators=130, max_features='sqrt', max_depth=5, min_samples_split=1200, min_samples_leaf=60, subsample=0.8, random_state=10)
model.fit(train_part, train_part_y)
pred = model.predict_proba(valid_part)[:, 1]
print(model)
print("auc score: ", roc_auc_score(valid_part_y, pred))
