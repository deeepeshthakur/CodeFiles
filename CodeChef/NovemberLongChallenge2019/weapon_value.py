import math
import numpy as np

tc = int(input())

ans_str = ""
for t in range(0,tc):
	n = int(input())
	arr = []
	for i in range(0,10):
		arr.append(0)

	# str_arr = []
	for i in range(0,n):
		input_str = input()
		for j in range(0,10):
			if input_str[j] == '1':
				arr[j] += 1;

	ans = 0
	for i in range(0,10):
		ans += arr[i]%2

	ans_str = ans_str + str(ans) + "\n"

print(ans_str,end="")


