t=13
for test in range(t):
    l=list(map(int,input().split()))
    if l[0]==1:
        n,k=l[1],l[2]
        dp = []
        for i in range(n):
            dp.append(list(map(int,input().split())))
        for i in range(n):
            st=set()
            for j in range(n):
                st.add(dp[i][j])
            if(len(st) != n):
                print(len(st), " +++ ",test+1)
            
        for j in range(n):
            dt=set()
            for i in range(n):
                dt.add(dp[i][j])
            if(len(dt)!=n):
                print(len(dt)," ---",test+1)
        sm=0
        for i in range(n):
            sm+=dp[i][i]
        if(sm != k):
            print("Not equak")
            


