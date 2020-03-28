def pow_mod(a,b,mod):
	if a==0:
		return a
	elif b==0:
		return 1
	elif b==1:
		return a%mod

	x = pow_mod(a,b//2,mod)
	x = (x*x)%mod
	if b%2 == 1:
		return (x*a)%mod
	return x

def sum_function(p,r,ind,n,mod):
	# print(p,r,ind,n,mod)
	if n-ind+1<=0:
		return 0
	p_to_r = pow_mod(p,r,mod)
	p_to_ind_r = pow_mod(p,ind*r,mod)
	inv_dn = pow_mod((p_to_r-1+mod)%mod,mod-2,mod)
	num = (pow_mod(p_to_r,n-ind+1,mod)-1+mod)%mod
	return (p_to_ind_r*((num*inv_dn)%mod))%mod

# mod = 998244353 
# tc = int(input())
# ans_str = ""
# for t in range(tc):
# 	n,p,r = list(map(int,input().split()))
# 	coeff_vec = None
# 	if r <= 1000:
# 		tmp_vec, coeff_vec = [0 for i in range(r+1)], [0 for i in range(r+1)]
# 		coeff_vec[0] = 1
# 		for i in range(0,r):
# 			for j in range(0,r+1):
# 				tmp_vec[j] = (coeff_vec[j]*(-i) + mod*abs(i))%mod
# 			for j in range(0,r):
# 				tmp_vec[j+1] = (coeff_vec[j]+tmp_vec[j+1]+3*mod)%mod
# 			for j in range(len(coeff_vec)):
# 				coeff_vec[j]=tmp_vec[j]
# 				tmp_vec[j]=0
# 			# print(coeff_vec)
# 		ans = 0
# 		# print(coeff_vec)

# 		ind=0
# 		while(p**ind < r):
# 			ind += 1

# 		pow_arr = [0 for i in range(r+1)]
# 		for i in range(1,r+1):
# 			pow_arr[i] = sum_function(p,i,ind,n,mod)
# 		# print(pow_arr)

# 		for i in range(r+1):
# 			ans += (pow_arr[i]*coeff_vec[i])%mod
# 			ans %= mod
# 		fact_r = 1
# 		for i in range(1,r+1):
# 			fact_r = (fact_r*i)%mod
# 		ans = (ans*pow_mod(fact_r,mod-2,mod))%mod
# 		print(ans)


