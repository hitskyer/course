def f(n):
    n1=1
    n2=1
    n3=1
    if n <1:
        print("enter has an error")
        return -1
    while (n-2)>0:
        n3=n2+n1
        n1=n2
        n2=n3
        n -= 1
    return n3

res=f(int(input("enter a int num")))
if res != -1:
    print("all num is ",res,"end")
    

def fa(n):
    if n<1:
        print("enter error")
        return -1
    if n==1 or n==2:
        return 1
    else:
        return fa(n-1)+fa(n-2)
res=fa(int(input("enter a int num")))
if res != -1:
    print("all num is ",res,"end")    
