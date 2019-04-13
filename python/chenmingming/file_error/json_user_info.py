import json
def get_num():
    try:
        global favor_num
        favor_num = int(input("输入你喜欢的数字："))

    except ValueError:
        print("你输入的不是数字，请重新输入！")
        get_num()
    return favor_num

def store_num(num):
    filename = "user_favor_num.json"
    with open(filename, 'a') as file:
        json.dump(num, file)

def getAndStore():
    store_num(get_num())

def print_num():
    filename = "user_favor_num.json"
    try:
        with open(filename) as file:
            num = json.load(file)
    except FileNotFoundError:
        getAndStore()
    else:
        print("i know your favorite number! it is ", num)

print_num()