import sys
def bit(a):
    c=0
    while a>0:
        if a&1:
            c+=1
        a=a>>1
    return c
cost=[[3,2,7],[5,1,3],[2,7,2]]
dp=[sys.maxsize]*8
dp[0]=0
for i in range(8):
    x=bit(i)
    for j in range(3):
        if not i&(1<<j):
            dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+cost[x][j])
print(dp)
