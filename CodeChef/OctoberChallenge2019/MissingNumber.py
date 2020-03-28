import math
import numpy as np

x_max = int(1e12)

def get_numb(a):
	ans = []
	l = len(a)
	for i in range(0,40):
		if i < l:
			if ord(a[l - 1 - i]) <= 57:
				ans.append(int(ord(a[l - 1 - i]) - ord('0')))
			else:
				ans.append(int(ord(a[l - 1 - i]) - ord('A') + 10))
		else:
			ans.append(0)

	return ans

def get_min_base(a):
	ans = 2
	for i in range(0,len(a)):
		if a[i] + 1 > ans:
			ans = a[i] + 1
	return ans

def get_num(a,b):
	ans = 0
	curr_mul = 1
	ind = 0

	while (ind < len(a)) and (ans <= x_max):
		ans = ans + curr_mul*a[ind]
		ind += 1
		curr_mul *= b

	return min(ans,x_max+10)


t = int(input())
ans_str = ""
for tc in range(0,t):
	n = int(input())
	bases = []
	numbs = []
	for i in range(0,n):
		a, b = list(input().split())
		bases.append(int(a))
		numbs.append(get_numb(b))

	ans = []
	for i in range(0,n):
		tmp = set()
		if bases[i] == -1:
			min_base = get_min_base(numbs[i])
			# print(i+1,min_base,end="    ---   ")
			for j in range(min_base,37):
				tmp_ans = get_num(numbs[i],j)
				# print(j,tmp_ans,end="  ")
				if tmp_ans <= x_max:
					tmp.add(tmp_ans)
			# print()
		else:
			for j in range(bases[i],bases[i]+1):
				tmp_ans = get_num(numbs[i],j)
				# print(j,tmp_ans,end="  ")
				if tmp_ans <= x_max:
					tmp.add(tmp_ans)
			# print()
		ans.append(tmp)

	ans_set = ans[0]
	for i in range(0,n):
		ans_set = ans_set & ans[i]

	final_ans = -1
	if len(ans_set) > 0:
		tmp_ans = x_max + 10
		for e in ans_set:
			if e < tmp_ans:
				tmp_ans = e
		final_ans = tmp_ans

	ans_str = ans_str + str(final_ans) + "\n"

print(ans_str,end="")