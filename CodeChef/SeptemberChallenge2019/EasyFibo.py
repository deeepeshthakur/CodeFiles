import math
import numpy as np

def pown(arr,n):
	if n == 0:
		return np.array([[1,0],[0,1]])

	if n == 1:
		return np.remainder(arr,10)
	t = pown(arr,n//2)
	ret_arr = np.remainder(np.linalg.matrix_power(t,2),10)

	if n%2 == 1:
		return np.remainder(np.matmul(ret_arr,arr),10)

	return ret_arr

arr1 = [0,1]
for i in range(2,100):
	arr = np.array([[1,1],[1,0]])
	tmp = np.remainder(pown(arr,2**i-1),10)

	arr1.append(tmp[0,1])

def easy_fib(x):
	i = 0
	while 2**(i+1) - 1 < x:
		i += 1

	return arr1[i]

n = int(input())

input_list = []
for i in range(0,n):
	input_list.append(int(input()))

ans = ""
for i in input_list:
	ans = ans + str(easy_fib(i)) + "\n"

print(ans,end="")
