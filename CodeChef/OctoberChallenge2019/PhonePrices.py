import math
import numpy as np

t = int(input())

def gt_min(arr,l,r):
	ans = arr[r]
	for i in range(l,r):
		if ans > arr[i]:
			ans = arr[i]
	return ans

for tc in range(0,t):
	n = int(input())
	arr = list(map(int,input().split()))

	ans = 1
	for i in range(1,n):
		l = max(0,i-5)
		r = i-1
		if gt_min(arr,l,r) > arr[i]:
			ans = ans + 1
	print(ans)
