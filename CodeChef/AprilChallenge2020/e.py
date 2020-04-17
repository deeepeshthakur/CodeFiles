test = int(input())
ans_str=""

for t in range(test):
    n=int(input())
    a=list(map(int,input().split()))

    ans=0
    l,r=0,0
    for i in range(len(a)):
        if a[i]%4==2:
            l,r=1,1
            while i-l>=0 and a[i-l]%2==1:
                l+=1
            while i+r<n and a[i+r]%2==1:
                r+=1
            ans+=l*r
    
    ans_str=ans_str+str((n*n+n)//2 - ans)+"\n"

print(ans_str,end="")