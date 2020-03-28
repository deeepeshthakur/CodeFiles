import numpy as np

b = np.array([[1, 1],[1, 0]])

def fib_rec(n):
	global b
	if n == 0:
		return np.array([[1, 0],[0, 1]])

	if n == 1:
		return b.copy()

	c = fib_rec(n//2)%10000
	if n%2 == 1:
		c = np.matmul(np.matmul(c,c),b)%10000
	else:
		c = np.matmul(c,c)%10000
	# print(n, c)
	return c%10000

def fib_fun(n):
	if n == 0:
		return 0
	if n == 2:
		return 1
	if n == 3:
		return 1
	ans = fib_rec(n)
	return ans[0][1]%10000

t = int(input())
ans_str = ""
for tc in range(t):
	m,n = list(map(int,input().split()))
	ans = ((fib_fun(n+1)%10000) + 10000 - (fib_fun(m)%10000))%10000
	ans_str = ans_str + str(ans) + "\n"
print(ans_str,end="")