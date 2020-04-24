# def f(n):
#     l=[True for i in range(n)]
#     ctr=n
#     curr,d=0,1
#     while ctr>1:
#         curr%=n
#         while ctr>1 and curr<n:
#             if l[curr]:
#                 d+=1
#             if d%2==0:
#                 d=0
#                 l[curr]=False
#                 ctr-=1
#             curr+=1
#         # print(l)

#     ans=-1
#     for i in range(n):
#         if l[i]:
#             ans=i+1
#     return ans

test_c=int(input())
ans_str=""
for t in range(test_c):
    n,k=list(map(int,input().split()))
    ini=(2+2*k)%n
    if ini==0:
        ini=n
    ans=0
    if n%2==0:
        ans=ini-1
    else:
        ans=ini-2
    if ans<=0:
        ans+=n
    ans_str=ans_str+str(ans)+"\n"

print(ans_str,end="")