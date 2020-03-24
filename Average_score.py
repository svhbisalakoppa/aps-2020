a=list(map(float,input().split()))
s=0
for i in range(len(a)):
s+=a[i]
print(s/(i+1),end=&#39; &#39;)
