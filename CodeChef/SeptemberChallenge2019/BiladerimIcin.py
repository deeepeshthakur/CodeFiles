import numpy as np
import math

t_cases = int(input())
MOD = 1000000000 + 7

bmax = 5000
sq_integers = []
sum_sq_integers = []
for i in range(1,bmax+1):
	sq_integers.append(i*i)
	sum_sq_integers.append(0)

for i in range(0,bmax):
	if i == 0:
		sum_sq_integers[i] = sq_integers[i]
	else:
		sum_sq_integers[i] = sq_integers[i] + sum_sq_integers[i-1]

def get_sum_sq(a,b):
	if a > b:
		return 0
	if a == 1:
		return sum_sq_integers[b-1]

	return sum_sq_integers[b - 1] - sum_sq_integers[a - 2]

dp_rem_sq = []
for i in range(1,bmax+1):
	tmp_lst = []
	sm = 0
	for j in range(0,bmax//50):
		for k in range(j*50 + 1,j*50 + 51):
			if k > i:
				sm += (k*k)%i
		tmp_lst.append(sm)
	dp_rem_sq.append(tmp_lst)

def f4(a,b,bm,c):
	if a < b or c < b:
		return 0

	return (bm - b + 1 + MOD)%MOD

def f3(a,b,bm):

	if a <= b or b >= bm:
		return 0

	if a < (bm*bm)//b:
		sqrt_ab = int(math.sqrt(a*b))
		ans = f3(a,b,sqrt_ab) + max(0,bm-max(b,sqrt_ab))*max(0,a-b)
		return ans%MOD

	ind = bm//50 - 1
	ans = 0
	
	if ind >= 0:
		ans = get_sum_sq(b,(ind)*50+50) - dp_rem_sq[b-1][ind]

	# print(b, ind, ans, ans%b)
	ans = (ans//b)%MOD;

	for i in range((bm//50)*50+1,bm+1):
		if i >= b:
			ans += ((i*i)//b)%MOD
			ans = ans%MOD
	ans = (ans - (b*max(bm-b+1,0))%MOD + MOD)%MOD
	return ans

def f2(a,b,bm,c):
	if a < b or c < b:
		return 0
	tmp = (f3(a,b,bm) + f3(c,b,bm) + f4(a,b,bm,c))%MOD
	return tmp

def f_501(a,b,c):
	ans = 0

	for i in range(1,b+1):
		ans += f2(a,i,b,c)%MOD

	ans = ((a*b*c)%MOD + MOD - (ans%MOD))%MOD
	return ans%MOD;

def exc(a,x,b,c):
	if 1 <= x and x <= a and x <= c:
		return max(min((b*b)//x,a) - x,0) + max(min((b*b)//x,c) - x,0) + 1
	return 0


def triple_b(a,b,c):
	if a*c == 0 or (b*b - a*c) >= 0 :
		return 0

	sm = 0
	for i in range(1,b+1):
		sm = (sm + exc(a,i,b,c))%MOD
	sm = (a*c - sm + MOD)%MOD
	return sm%MOD

ans = ""
for i in range(0,t_cases):
	a, b, c = list(map(int,input().split()))
	sm = 0
	if b <= 100:
		for i in range(1,b+1):
			sm = (sm + triple_b(a-1,i,c-1))%MOD
	else:
		sm = f_501(a-1,b,c-1)%MOD

	ans = ans + str(sm) + "\n"

print(ans,end="")