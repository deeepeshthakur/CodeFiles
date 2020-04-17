test_c=int(input())
ans_str=""
for i in range(test_c):
    n=int(input())
    p=list(map(int,input().split()))
    ans=True
    prev=-10
    for i in range(n):
        if(p[i]==1):
            if i-prev<6:
                ans=False
            prev=i
    if ans:
        ans_str=ans_str+"YES\n"
    else:
        ans_str=ans_str+"NO\n"

print(ans_str,end="")