import math
import numpy as np

t = int(input())

for tc in range(0,t):
	n, m, q = list(map(int,input().split()))
	x_arr = []
	y_arr = []
	for i in range(0,q):
		a,b = list(map(int,input().split()))
		x_arr.append(a)
		y_arr.append(b)
	# x_arr = list(map(int,input().split()))
	# y_arr = list(map(int,input().split()))

	lx = []
	ly = []

	for i in range(0,n):
		lx.append(0)

	for i in range(0,m):
		ly.append(0)

	for i in range(0,q):
		lx[x_arr[i]-1] += 1
		ly[y_arr[i]-1] += 1

	tx = 0
	ty = 0
	for i in range(0,n):
		tx += (lx[i]%2)

	for i in range(0,m):
		ty += (ly[i]%2)

	ans = (n-tx)*ty + (m-ty)*tx
	print(ans)

