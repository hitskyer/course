enter = 'y'
while enter == 'y':
    name = input("请输入你的名字：")
    filename = "guest_record.txt"
    if name != "":
        with open(filename, 'a', encoding='utf-8') as file:
            file.write(name + '\n')
        print("hello, ", name, " !")
        conti = 'y'
        while conti == 'y':
            reason = input("你为什么喜欢python？")
            with open(filename, 'a', encoding='utf-8') as file:
                file.write(reason + '\n')
            conti = input("继续输入原因吗？y/n ")
    enter = input("继续访问吗？y/n ")