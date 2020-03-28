def pow_mod(a,b,mod):
	if a == 0:
		return 0
	if b == 0:
		return 1
	if b == 1:
		return a%mod

	x = pow_mod(a,b//2,mod)%mod
	x = (x*x)%mod
	if b%2 == 1:
		return (x*a)%mod
	return x

def ncr(n,i,num,den,mod):
	if i == 0 or i == n:
		return 1
	den = pow_mod(den,mod-2,mod)%mod
	return (num*den)%mod

tc = int(input())
ans_str=""
for t in range(tc):
	n = int(input())
	a = input()
	b = input()

	x1,x2,y1,y2=0,0,0,0
	ans,mod = 0,int(1e9)+7
	for i in range(n):
		x1 += (1 if a[i] == '0' else 0)
		x2 += (1 if b[i] == '0' else 0)
	y1=n-x1
	y2=n-x2
	pair_zero = min(x1,x2)
	pair_one = min(y1,y2)
	# print(max_pair,max_non_pair)
	nfact_Array = [1 for i in range(n+1)]
	for i in range(1,len(nfact_Array)):
		nfact_Array[i] = (nfact_Array[i-1]*i)%mod

	flag = True
	while flag:
		i = n-(pair_one + pair_zero)
		if i >= 0 and i <= n+1:
			ans += ncr(n,i,nfact_Array[n],(nfact_Array[i]*nfact_Array[n-i])%mod,mod)
			ans = ans%mod
		if pair_zero > 0 and pair_one > 0:
			pair_one -= 1
			pair_zero -= 1
		else:
			flag = False

	ans_str = ans_str + str(ans) + "\n"

print(ans_str,end="")

