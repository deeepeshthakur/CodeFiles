def bc(n):
    ans=0
    while n>0:
        ans+=(1 if n%2==1 else 0)
        n=n//2
    return ans

for i in range(1000):
        print(bin(i),i,("-------------" if bc(i)%2==0 else "+"))

print()