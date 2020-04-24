test_c=int(input())

ans_str=""
for t in range(test_c):
    lst=list(input().split())
    n,m,c=int(lst[0]),int(lst[1]),lst[2][0]
    if c=='R':
        m=16-m
    binary = [0 for i in range(16)]
    for i in range(16):
        binary[15-i]=n%2
        n//=2
    ans=0
    for i in range(16):
        ans+=binary[(m+i)%16]*(2**(15-i))
    ans_str=ans_str+str(ans)+"\n"
print(ans_str,end="")
