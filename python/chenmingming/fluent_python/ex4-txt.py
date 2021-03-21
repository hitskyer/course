s = 'café'
print(len(s))  # 4
b = s.encode('utf-8')
print(b)  # b'caf\xc3\xa9'
print(len(b))  # 5
print(b.decode('utf-8'))  # café
