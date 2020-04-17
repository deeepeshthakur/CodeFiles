test_c=int(input())
ans_str=""
for i in range(test_c):
    n=int(input())
    p=list(map(int,input().split()))
    p.sort(reverse=True)
    ans=0
    for i in range(n):
        ans=ans+max(p[i]-i,0)
    ans=ans%1000000007
    ans_str=ans_str+str(ans)+"\n"

print(ans_str,end="")