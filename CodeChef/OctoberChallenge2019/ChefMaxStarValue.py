# import math
# import numpy as np
# import time


t = int(input())
# start_time = time.time()

fact = []
fact_ln = int(1e6+10)
for i in range(0,fact_ln):
	fact.append([i])

for i in range(2,fact_ln):
	if i*i < fact_ln:
		fact[i*i].append(i)
	ind = i + 1
	while ind*i < fact_ln:
		fact[i*ind].append(i)
		fact[i*ind].append(ind)
		ind += 1

# print(time.time()-start_time)

# for i in range(len(fact)-100,len(fact)):
# 	print(i, end = "   ")
# 	for j in range(0,len(fact[i])):
# 		print(fact[i][j],end=' ')
# 	print()
str_ans = ""
tr_arr = []
for i in range(0,fact_ln):
	tr_arr.append(0)
	
for tc in range(0,t):
	n = int(input())
	arr = list(map(int,input().split()))

	for i in range(0,len(tr_arr)):
		tr_arr[i] = 0

	ans = 0
	for i in range(0,n):
		ans = max(ans,tr_arr[arr[i]])
		for j in range(0,len(fact[arr[i]])):
			tr_arr[fact[arr[i]][j]] += 1
		tr_arr[1] += 1

	str_ans = str_ans + str(ans) + "\n"

print(str_ans,end="")