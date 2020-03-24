n,k=map(int,input().split())
a=[]
for j in range(n):
a.append(input())
a=sorted(a)
x=&#39;&#39;
c=1
y=1
for i in range(n):
if len(a[i])&gt;=k:
x=a[i][:k]
break
if i==n-1 and len(x)!=k:
print(0)
exit(0)
for j in range(i+1,n):
if a[j][:k]==x:
c+=1
else:
x=a[j][:k]
if c&gt;y:

y=c
c=1
if y&gt;c:
print(y)
else:
print(c)
