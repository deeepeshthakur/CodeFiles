test_c=int(input())
ans=[0 for i in range(test_c)]

is_prime = [True for i in range(0,int(1e5)+1)]
is_prime[0]=False
is_prime[1]=False
for i in range(len(is_prime)):
    if is_prime[i]:
        j=2
        while(j*i<len(is_prime)):
            is_prime[i*j]=False
            j+=1

primes=[]
for i in range(len(is_prime)):
    if(is_prime[i]):
        primes.append(i)

for t in range(test_c):
    x,k=list(map(int,input().split()))
    tmp=[]
    for i in range(len(primes)):
        while x%primes[i]==0:
            x/=primes[i]
            tmp.append(primes[i])
    if x>1:
        tmp.append(x)
    
    if k<=len(tmp):
        ans[t]=1

for i in range(test_c):
    print(ans[i])