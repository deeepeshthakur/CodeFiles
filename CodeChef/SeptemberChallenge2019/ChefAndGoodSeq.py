import math
import numpy as np
MOD = 1000000000 + 7

input_str = input()
list = input_str.split()

n ,k = int(list[0]), int(list[1])


input_str = input()
list = input_str.split()
arr = []

for i in range(0,n):
	arr.append(int(list[i]))

arr.sort()

a = []
ctr = []

for i in range(0,n):
	if i == 0:
		a.append(arr[i])
		ctr.append(1)
	else:
		t = len(a) - 1
		if a[t] == arr[i]:
			ctr[t] += 1
		else:
			a.append(arr[i])
			ctr.append(1)

n = len(a)

tmp1 = []
tmp2 = []

for i in range(0,n+2):
	tmp1.append(0)
	tmp2.append(0)

tmp1[0] = 1

for i in range(0,n):
	for j in range(0,n+2):
		tmp2[j] += tmp1[j]
		if j + 1 < n + 2:
			tmp2[j+1] += (ctr[i]*tmp1[j])%MOD

	for j in range(0,n+2):
		tmp1[j] = tmp2[j]
		tmp2[j] = 0

sm = 0
k = min(k,n+1)
for i in range(0,k+1):
	sm = (sm + tmp1[i])%MOD

print(sm)