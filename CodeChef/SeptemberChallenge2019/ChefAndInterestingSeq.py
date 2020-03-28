import numpy as np
import math

t_cases = int(input())
ans_list = ""
for i in range(0,t_cases):
	input_list = input()
	list = input_list.split()
	# print(list)
	n, k = int(list[0]), int(list[1])

	arr = []
	input_list = input()
	list = input_list.split()
	# print(input_list)
	for i in range(0,n):
		arr.append(int(list[i]))
	arr.sort()
	
	sm = 0
	for i in range(0,k):
		sm += arr[i] 

	ctr, ctrk = 0, 0
	for i in range(0,n):
		if arr[i] < arr[k-1]:
			ctr += 1

		if arr[i] == arr[k-1]:
			ctrk += 1

	ctr = k - ctr

	ans = math.factorial(ctrk)//(math.factorial(ctr)*math.factorial(ctrk-ctr))
	ans_list = ans_list + str(ans) + "\n"

print(ans_list,end="")




