import json
numbers = [2, 3, 5, 7, 11, 13]
filename = "numbers.json"
with open(filename,'w') as file:
    json.dump(numbers,file)

with open(filename) as file:
    numbers = json.load(file)
print(numbers)

def get_stored_username():
    filename = "username.json"
    try:
        with open(filename) as file:
            username = json.load(file)
    except FileNotFoundError:
        return None
    else:
        return username

def get_new_username():
    username = input("What is your name? ")
    filename = "username.json"
    with open(filename, 'a') as file:
        json.dump(username, file)
    return username

def greet_user():
    username = get_stored_username()
    if username:
        print("Welcome back, ", username, " !")
    else:
        get_new_username()
        print("We'll remember you when you come back, ", username, " !")

greet_user()
