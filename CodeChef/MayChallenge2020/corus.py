test=int(input())
ans_str=""

for t in range(test):
    n,q=list(map(int,input().split()))
    s=input()
    dp=[0 for i in range(26)]
    for i in range(n):
        dp[ord(s[i])-ord('a')]+=1
    for i in range(q):
        c=int(input())
        ans=0
        for j in range(len(dp)):
            ans+=max(0,dp[j]-c)
        
        ans_str=ans_str+str(ans)+"\n"

print(ans_str,end="")
