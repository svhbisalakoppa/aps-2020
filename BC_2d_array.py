n=int(input())
k=int(input())
c=[[0 for i in range(n+1)]for j in range(k+1)]
c[0][0]=1
for i in range(n+1):
    for j in range(min(i+1,k+1)):
        if j==0 or j==i:
            c[i][j]=1
        else:
            c[i][j]=c[i-1][j-1]+c[i-1][j]
print(c)
