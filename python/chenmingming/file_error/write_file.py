filename = "write_file.txt"
with open(filename,'w') as file:
    file.write("i love python very much !\n")
    file.write("so i write down it to programming.\n")

with open(filename, 'a') as file:   # a,追加模式
    file.write("i continue to learn python hard.\n")