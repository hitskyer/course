import json
numbers = [2, 3, 5, 7, 11, 13]
filename = "numbers.json"
with open(filename,'w') as file:
    json.dump(numbers,file)

with open(filename) as file:
    numbers = json.load(file)
print(numbers)