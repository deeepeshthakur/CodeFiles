test=int(input())
ans_str=""

for t in range(test):
    n=list(map(int,input().split()))
    x=int(input())
    dp = []
    for i in range(x+1):
        dp.append([-1 for i in range(x+1)])
    
    dp[0][0] = 1
    vis = [True for i in range(x+1)]
    for i in range(len(dp)):
        for j in range(len(dp[i])):
            if(dp[i][j]==1 and vis[j]):
                vis[j]=False
                for k in range(len(n)):
                    if (i+1<x+1 and j+n[k]<x+1 and vis[j+n[k]]):
                        dp[i+1][j+n[k]]=1

    ans=x+1
    for i in range(len(dp)):
        if(dp[i][x]==1):
            ans=min(ans,i)
    
    ans_str=ans_str+str(ans)+"\n"

print(ans_str,end="")


