filename = 'pi_digits.txt'
with open(filename) as pi_file: #with帮助我们适时关闭文件
    lines = pi_file.readlines()	#把文件按行存储
pi_str = ''
for line in lines:
    pi_str += line.strip()	#strip()行左右的空删除
print(pi_str[:7]+"...")
print(len(pi_str))
birthday = input("输入你的生日：yyyymmdd ")
if birthday in pi_str:
    print("你的生日出现在pi中。")
else:
    print("你的生日不在pi中。")