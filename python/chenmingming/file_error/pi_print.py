filename = 'pi_digits.txt'
with open(filename) as pi_file: #with帮助我们适时关闭文件
    for line_content in pi_file:
        print(line_content.rstrip())