import math
import numpy as np

seq = []
for i in range(0,129):
	seq.append([])

seq[0].append(1)
prev = 0
for index in range(2,129):
	if len(seq[prev]) < 2:
		prev = 0
	else:
		l = len(seq[prev])
		prev = (seq[prev][l-1] - seq[prev][l-2])
	seq[prev].append(index)

arr = []
for i in range(0,128):
	arr.append(0)

for i in range(0,129):
	for j in range(0,len(seq[i])):
		arr[seq[i][j]-1] = i

t = int(input())

ans_str = ""
for tc in range(t):
	n = int(input())
	x = arr[n-1]

	ans = 0
	for i in range(0,n):
		if arr[i] == x:
			ans += 1
			
	ans_str = ans_str + str(ans) + "\n";

print(ans_str,end="")