test_c=int(input())
ans_str=""
for i in range(test_c):
    n=int(input())

    if n%2==1:
        if n>1:
            ans_str=ans_str+str(n//2)+"\n"
            for i in range(1,n//2+1):
                if i==1:
                    ans_str=ans_str+"3 "+str(n)+" 1 2\n"
                else:
                    ans_str=ans_str+"2 "+str(2*i-1)+" "+str(2*i)+"\n"
        else:
            ans_str=ans_str+"1\n1 1\n"
    else:
        ans_str=ans_str+str(n//2)+"\n"
        for i in range(1,n//2+1):
            if i==1:
                ans_str=ans_str+"2 1 2\n"
            else:
                ans_str=ans_str+"2 "+str(2*i-1)+" "+str(2*i)+"\n"

print(ans_str,end="")