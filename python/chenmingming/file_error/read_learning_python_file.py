filename = 'learning_python.txt'
with open(filename) as file:
    '''方法1:整个文件一次读取'''
    # print(file.read())
    '''方法2：分行读取'''
    # for line in file.readlines():
    #     print(line.strip())
    '''方法3'''
    line1 = file.readlines()

for l in line1:
    print(l.replace("Python", "C++").strip())

