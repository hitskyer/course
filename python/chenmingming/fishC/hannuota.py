def hanoi(n,x,y,z):
    if n==1:
        print(x,"-->",z)
    else:
        # 将前n-1个盘子从x移到y
        hanoi(n-1,x,z,y)
        # 将最底下的最后一个从x移到z
        print(x,"-->",z)
        # 将y上的n-1个移到z
        hanoi(n-1,y,x,z)
    
n = int(input("请输入汉诺塔层数："))
hanoi(n,'x','y','z')
