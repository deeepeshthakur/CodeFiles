import math
import numpy as np

t = int(input())

for tc in range(0,t):
	n, k = list(map(int,input().split()))
	arr = list(map(int,input().split()))

	if k > 3*n:
		if n%2 == 1:
			arr[(n-1)//2] = 0
		k = k%(3*n)

	for i in range(0,k):
		arr[i%n] = (arr[i%n]^arr[n-1-(i%n)])

	for i in range(0,n):
		if i + 1 < n:
			print(arr[i], end = ' ')
		else:
			print(arr[i])
 

# print(t, n, k)
# print(arr)