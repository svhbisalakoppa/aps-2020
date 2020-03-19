BIT=[0]*11
n=10
def update(i,v):
    i += 1 
    while i <= n: 
        BIT[i] += v 
        i += i & (-i)
def quiry(i):
    s=0
    i=i+1
    while i > 0:
        s += BIT[i]
        i -= i & (-i) 
    return s
for i in range(0,n):
    v=int(input())
    update(i,v)
print(quiry(3))
print(BIT)
