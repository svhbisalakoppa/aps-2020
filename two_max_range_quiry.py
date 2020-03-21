import sys
n=int(input())
a=list(map(int,input().split()))
maxi=maxim=-sys.maxsize-1
tmax=0
fis=0
las=n
for i in range(n):
    tmax+=a[i]
    if(maxi<tmax):
        maxi=tmax
        las=i
    if tmax<0:
        tmax=0
s=0
for j in range(las,0,-1):
    s+=a[j]
    if s==maxi:
        fis=j
        break;   
print(maxi)
if fis==n:
    del a[las]
    x=n-1
else:
    del a[fis:las+1]
    x=(n-1)-(las-fis)
if a==[]:
    print("0")
    exit()
tmax=0
for i in range(x):
    tmax+=a[i]
    if(maxim<tmax):
        maxim=tmax
    if tmax<0:
        tmax=0
print(maxim)
