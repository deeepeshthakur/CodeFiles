import numpy as np
import math

maxn = 1000000
n = int(input())

arr = []
str_list = input()
int_list = str_list.split()

for i in range(0,n):
	t = int(int_list[i])
	if t <= maxn:
		arr.append(t)

n = len(arr)
arr.sort()

visited = []
for i in range(0,maxn+1):
	visited.append(True)

visited[0] = False

for i in range(0,n):
	a = arr[i]
	if visited[a]:
		for j in range(1,a+1):
			if (not visited[j]):
				k = 1
				while(j + a*k < len(visited)):
					visited[j + a*k] = False
					k += 1


