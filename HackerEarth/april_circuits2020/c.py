test_c=1
ans_str=""
for i in range(test_c):
    n,m=list(map(int,input().split()))
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    a.sort()
    b.sort()
    ans=0
    if b[m-1]>=a[n-1]:
        l,r,mid=1,n,0
        while(r-l>1):
            mid=(l+r)//2
            flag=bool(m*mid>=n)
            i=0
            while n-i*mid-1>=0 and i<m and flag:
                if a[n-i*mid-1]>b[m-1-i]:
                    flag=False
                i+=1
            if flag:
                r=mid
            else:
                l=mid
        flag=bool(l*m>=n)
        i=0
        while n-i*l-1>=0 and i<m and flag:
            if a[n-i*l-1]>b[i]:
                flag=False
            i+=1
        if flag:
            r=l
        ans=r+1
    else:
        ans=-1
    ans_str=ans_str+str(ans)+"\n"

print(ans_str,end="")