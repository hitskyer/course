print("input 2 numbers to divide, enter 'q' to quit.")
while True:
    first = input("\nfirst num: ")
    if first == 'q':
        break
    second = input("\nsecond num: ")
    try:
        answer = int(first) / int(second)
    except ZeroDivisionError:
        print("divide zero!!!")
    else:
        print(answer)
    break

filename = 'learning_python.txt'
try:
    with open(filename) as f_obj:
        contents = f_obj.read()
except FileNotFoundError:
    msg = "Sorry, the file " + filename + " does not exist."
    print(msg)
    # pass  #一言不发，跳过
else:
    words = contents.split()
    print("the title ", filename, " has ", str(len(words)), " words.")

while True:
    print("input 2 nums : ")
    try:
        a = int(input('first num: '))
    except ValueError:
        print("请输入数字！")
        continue
    try:
        b = int(input('second num: '))
    except ValueError:
        print("请输入数字！")
        continue
    print("sum of two nums is ", a+b)