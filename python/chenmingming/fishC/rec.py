def factorial(n):
    result = n
    for i in range(1,n):
        result *= i
    return result

num=int(input("enter a int num:"))
res=factorial(num)
print(res)

def factor(n):
    if n==1:
        return 1
    else:
        return n*factor(n-1)


num=int(input("enter a int num:"))
res=factor(num)
print(res)

