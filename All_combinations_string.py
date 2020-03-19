a=input()
n=3
for i in range(1<<n):
    for j in range(n):
        if(i&(1<<j)):
            print(a[j],end='')
    print()
