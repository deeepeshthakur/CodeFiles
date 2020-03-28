test_c=int(input())

for i in range(test_c):
    n,m = list(map(int, input().split()))
    a = [0 for i in range(m)]
    b = [0 for i in range(m)]

    f = list(map(int,input().split()))
    p = list(map(int,input().split()))

    for i in range(n):
        a[f[i]-1]+=p[i]
        b[f[i]-1]+=1
    
    ans,pr=0,1000000
    for i in range(m):
        if b[i]>0 and a[i]<pr:
            ans=i
            pr=a[i]
    
    print(pr)
