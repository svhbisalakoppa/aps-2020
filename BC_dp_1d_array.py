n=int(input())
k=int(input())
c=[0]*(n+1)
c[0]=1
for i in range(n+1):
    for j in range(min(i,k),0,-1):
        c[j]=c[j]+c[j-1]
print(c)
