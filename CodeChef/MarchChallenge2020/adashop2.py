test_c = int(input())
for i in range(test_c):
    r,c = list(map(int,input().split()))
    out_ = [[r,c]]
    if(r+c!=2):
        out_.append([(r+c)//2,(r+c)//2])
        out_.append([1,1])

    # out_.append([2,2])
    for i in range(2,8):
        out_.append([i,i])
        sm = i+i
        for j in range(1,8):
            if(i-j>0 and i-j<=8 and i+j>0 and i+j<=8):
                out_.append([i-j,i+j])
                out_.append([i+j,i-j])
        out_.append([i,i])
    
    out_.append([8,8])

    print(len(out_))
    for i in range(len(out_)):
        print(out_[i][0],out_[i][1])
    