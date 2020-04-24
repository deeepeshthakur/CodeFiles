test_c=int(input())
ans_str=""
for t in range(test_c):
    n=int(input())
    s=input()
    b=[0 for i in range(n)]
    for i in range(n):
        if s[i]=='A':
            b[i]=1
        if i>0:
            b[i]+=b[i-1]

    ans=b[n-1]
    for i in range(n):
        ans=min(ans,i+1-b[i]+b[n-1]-b[i])
    ans_str=ans_str+str(ans)+"\n"

print(ans_str,end="")
    
    