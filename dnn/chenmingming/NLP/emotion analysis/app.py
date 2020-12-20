# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/12/21 0:44
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: app.py
# @Reference: 

# Flask
import pickle
import numpy as np
from keras.preprocessing.sequence import pad_sequences
from keras.models import load_model
def load_var():
    global model, tokenizer
    model = load_model('trained_model.h5')
    model.make_predict_function()
    with open('trained_tokenizer.pkl','rb') as f:
        tokenizer = pickle.load(f)

maxlen = 50
def process_txt(text):
    x = tokenizer.texts_to_sequences(text)
    x = pad_sequences(x, maxlen=maxlen, padding='post')
    return x

#%%

from flask import Flask, request, jsonify
app = Flask(__name__)

@app.route('/')
def home_routine():
    return "hello NLP!"

#%%

@app.route("/prediction",methods=['POST'])
def get_prediction():
    if request.method == 'POST':
        data = request.get_json()
    x = process_txt(data)
    prob = model.predict(x)
    pred = np.argmax(prob, axis=-1)
    return str(pred)

#%%

if __name__ == "__main__":
    load_var()
    app.run(debug=True)
