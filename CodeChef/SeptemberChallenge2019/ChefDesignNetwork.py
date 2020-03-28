import math
import numpy as np

t_cases = int(input())

def f1(n,m,c):
	if c < 2 and m < n - 1:
		return False
	if c == n:
		return bool(m == (n*(n+1))//2)

	if c == 2:
		return bool((m >= n - 1) and (m <= n + 1))

	if c%2 == 1:
		return bool((max(c,n-1) <= m) and (m <= (1 + (c-1)//2)*n))
	else:
		return bool((max(c,n-1) <= m) and (m <= (c*n + n)//2))

def f0(n,m):
	if m < n - 1 or m > (n*(n+1))//2:
		return -1

	l, r = 2, n
	while(r - l > 1):
		mid = (l + r)//2
		if f1(n,m,mid):
			r = mid
		else:
			l = mid

	if bool(f1(n,m,l)):
		return l
	else:
		return r


ans = ""
for i in range(0,t_cases):
	inp_list = input()
	f_list = inp_list.split()
	n, m = int(f_list[0]), int(f_list[1])

	# print(n, " ", m)
	if n == 1:
		if m == 0:
			ans = ans + "0\n"
		
		if m == 1:
			ans = ans + "1\n"

		if m > 1:
			ans = ans + "-1\n"

	if n == 2:
		if m == 0 :
			ans = ans +"-1\n"

		if m == 1:
			ans = ans + "1\n"

		if (m > 1 and m <= 3):
			ans = ans + "2\n"

		if m > 3:
			ans = ans + "-1\n"

	if n > 2:
		ans = ans + str(f0(n,m)) + "\n"

print(ans,end="")
