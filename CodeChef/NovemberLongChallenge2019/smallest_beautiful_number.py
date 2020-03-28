import math
from math import floor, ceil, sqrt, log, log10
global_curr_num = [0 for i in range(0,9)]
pre_ = [0, 1, 34, 122, 1111, 11123, 111112, 1111124, 11111113, 111111111, 1111111114, 11111111126]
last_2 = [11, 12, 13, 14, 15, 16, 17, 18, 19, 22, 23, 24, 25, 26, 27, 28, 29, 33, 34, 35, 36, 37, 38, 39, 44, 45, 46, 47, 48, 49, 55, 56, 57, 58, 59, 66, 67, 68, 69, 77, 78, 79, 88, 89, 99]
diff_arr = [0, -1, -1, 2, -1, -1, 22, -1, 3, 222, -1, 23, 2222, -1, 223, 4, 33, 2223, 24, 233, 22223, 224, 2233, 34, 5, 22233, 234, 25, 222233, 2234, 44, 334, 35, 244, 2334, 6, 2244, 22334, 26, 45, 335, 226, 245, 36, 2226, 444, 236, 345, 7, 2236, 46, 27, 22236, 246, 227, 3345, 37, 2227, 346, 56, 4444, 2346, 256, 8, 337, 446, 28, 356, 2446, 228, 66, 38, 57, 266, 238, 257, 2266, 2238, 48, 338, 9, 248, 2338, 29, 2248, 466, 229, 58, 39, 2229, 258, 239, 22229, 448, 566, 49, 77, 2566, 68, 277, 4466, 268, 458, 349, 59, 666, 368, 259, 2666, 2368, 449, 78, 359, 468, 278, 69, 2468, 2278, 269, 378, 577, 2269, 568, 369, 22269, 2568, 88, 3378, 79, 288, 469, 279, 2288, 668, 388, 578, 379, 2388, 2578, 569, 6666, 488, 2569, 89, 777, 4469, 289, 2777, 4668, 2289, 588, 389, 579, 2588, 2389, 2579, 4488, 5668, 489, 778, 99, 688, 2778, 299, 2688, 4588, 2299, 589, 399, 3688, 2589, 2399, 23688, 4489, 788, 499, 779, 2788, 689, 2779, 22788, 2689, 3788, 3499, 599, 5688, 3689, 2599, 25688, 888, 4499, 789, 2888, 4689, 2789, 699, 6688, 3888, 2699, 3789, 5779, 22699, 5689, 3699, 4888, 25689, 889, 7778, 799, 2889, 4699, 2799, 22889, 5888, 3889, 5789, 3799, 23889, 25789, 5699, 56688, 4889, 7788, 899, 6888, 27788, 2899, 26888, 45888, 22899, 5889, 3899, 5799, 25889, 23899, 25799, 44889, 7888, 4899, 7789, 999, 6889, 27789, 2999, 26889, 37888, 22999, 5899, 3999, 36889, 25899, 23999, 8888, 44899, 7889, 4999, 7799, 27889, 6899, 27799, 38888, 26899, 37889, 34999, 5999, 56889, 36899, 25999, 256889, 8889, 44999, 7899, 28889, 46899, 27899, 6999, 58888, 38889, 26999, 37899, 57799, 226999, 56899, 36999, 48889, 77888, 8899, 68888, 7999, 28899, 46999, 27999, 228899, 58889, 38899, 57899, 37999, 238899, 257899, 56999, 78888, 48899, 77889, 8999, 68889, 277889, 28999, 268889, 378888, 228999, 58899, 38999, 57999, 258899, 238999, 88888, 448899, 78889, 48999, 77899, 9999, 68899, 277899, 29999, 268899, 378889, 229999, 58999, 39999, 368899, 258999, 239999, 88889, 448999, 78899, 49999, 77999, 278899, 68999, 277999, 388889, 268999, 378899, 349999, 59999, 568899, 368999, 259999, 778888, 88899, 449999, 78999, 288899, 468999, 278999, 69999, 588889, 388899, 269999, 378999, 577999, 2269999, 568999, 369999, 488899, 778889, 88999, 688889, 79999, 288999, 469999, 279999, 2288999, 588899, 388999, 578999, 379999, 2388999, 888888, 569999, 788889, 488999, 778899, 89999, 688899, 2778899, 289999, 2688899, 3788889, 2289999, 588999, 389999, 579999, 2588999, 2389999, 888889, 4488999, 788899, 489999, 778999, 99999, 688999, 2778999, 299999, 2688999, 3788899, 2299999, 589999, 399999, 3688999, 2589999, 2399999, 888899, 4489999, 788999, 499999, 779999, 2788999, 689999, 2779999, 3888899, 2689999, 3788999, 3499999, 599999, 5688999, 3689999, 2599999, 7788889, 888999, 4499999, 789999, 2888999, 4689999, 2789999, 699999, 5888899, 3888999, 2699999, 3789999, 5779999, 8888888, 5689999, 3699999, 4888999, 7788899, 889999, 6888899, 799999, 2889999, 4699999, 2799999, 22889999, 5888999, 3889999, 5789999, 3799999, 23889999, 8888889, 5699999, 7888899, 4889999, 7788999, 899999, 6888999, 27788999, 2899999, 26888999, 37888899, 22899999, 5889999, 3899999, 5799999, 25889999, 23899999, 8888899, 44889999, 7888999, 4899999, 7789999, 999999, 6889999, 27789999, 2999999, 26889999, 37888999, 22999999, 5899999, 3999999, 36889999, 25899999, 23999999, 8888999, 44899999, 7889999, 4999999, 7799999, 27889999, 6899999, 27799999, 38888999, 26899999, 37889999, 34999999, 5999999, 56889999, 36899999, 25999999, 77888899, 8889999, 44999999, 7899999, 28889999, 46899999, 27899999, 6999999, 58888999, 38889999, 26999999, 37899999, 57799999, 88888889, 56899999, 36999999, 48889999, 77888999, 8899999, 68888999, 7999999, 28899999, 46999999, 27999999, 228899999, 58889999, 38899999, 57899999, 37999999, 238899999, 88888899, 56999999, 78888999, 48899999, 77889999, 8999999, 68889999, 277889999, 28999999, 268889999, 378888999, 228999999, 58899999, 38999999, 57999999, 258899999, 238999999, 88888999, 448899999, 78889999, 48999999, 77899999, 9999999, 68899999, 277899999, 29999999, 268899999, 378889999, 229999999, 58999999, 39999999, 368899999, 258999999, 239999999, 88889999, 448999999, 78899999, 49999999, 77999999, 278899999, 68999999, 277999999, 388889999, 268999999, 378899999, 349999999, 59999999, 568899999, 368999999, 259999999, 778888999, 88899999, 449999999, 78999999, 288899999, 468999999, 278999999, 69999999, 588889999, 388899999, 269999999, 378999999, 577999999, 888888899, 568999999, 369999999, 488899999, 778889999, 88999999, 688889999, 79999999, 288999999, 469999999, 279999999, 2288999999, 588899999, 388999999, 578999999, 379999999, 2388999999, 888888999, 569999999, 788889999, 488999999, 778899999, 89999999, 688899999, 2778899999, 289999999, 2688899999, 3788889999, 2289999999, 588999999, 389999999, 579999999, 2588999999, 2389999999, 888889999, 4488999999, 788899999, 489999999, 778999999, 99999999, 688999999, 2778999999, 299999999, 2688999999, 3788899999, 2299999999, 589999999, 399999999, 3688999999, 2589999999, 2399999999, 888899999, 4489999999, 788999999, 499999999, 779999999, 2788999999, 689999999, 2779999999, 3888899999, 2689999999, 3788999999, 3499999999, 599999999, 5688999999, 3689999999, 2599999999, 7788889999, 888999999, 4499999999, 789999999, 2888999999, 4689999999, 2789999999, 699999999, 5888899999, 3888999999, 2699999999, 3789999999, 5779999999, 8888888999, 5689999999, 3699999999, 4888999999, 7788899999, 889999999, 6888899999, 799999999, 2889999999, 4699999999, 2799999999, 22889999999, 5888999999, 3889999999, 5789999999, 3799999999, 23889999999, 8888889999, 5699999999, 7888899999, 4889999999, 7788999999, 899999999, 6888999999, 27788999999, 2899999999, 26888999999, 37888899999, 22899999999, 5889999999, 3899999999, 5799999999, 25889999999, 23899999999, 8888899999, 44889999999, 7888999999, 4899999999, 7789999999, 999999999, 6889999999, 27789999999, 2999999999, 26889999999, 37888999999, 22999999999, 5899999999, 3999999999, 36889999999, 25899999999, 23999999999, 8888999999, 44899999999, 7889999999, 4999999999, 7799999999, 27889999999, 6899999999, 27799999999, 38888999999, 26899999999, 37889999999, 34999999999, 5999999999, 56889999999, 36899999999, 25999999999, 77888899999, 8889999999, 44999999999, 7899999999, 28889999999, 46899999999, 27899999999, 6999999999, 58888999999, 38889999999, 26999999999, 37899999999, 57799999999, 88888889999, 56899999999, 36999999999, 48889999999, 77888999999, 8899999999, 68888999999, 7999999999, 28899999999, 46999999999, 27999999999, 228899999999, 58889999999, 38899999999, 57899999999, 37999999999, 238899999999, 88888899999, 56999999999, 78888999999, 48899999999, 77889999999, 8999999999, 68889999999, 277889999999, 28999999999, 268889999999, 378888999999, 228999999999, 58899999999, 38999999999, 57999999999, 258899999999, 238999999999, 88888999999, 448899999999, 78889999999, 48999999999, 77899999999, 9999999999, 68899999999, 277899999999, 29999999999, 268899999999, 378889999999, 229999999999, 58999999999, 39999999999, 368899999999, 258999999999, 239999999999, 88889999999, 448999999999, 78899999999, 49999999999, 77999999999, 278899999999, 68999999999, 277999999999, 388889999999, 268999999999, 378899999999, 349999999999, 59999999999, 568899999999, 368999999999, 259999999999, 778888999999, 88899999999, 449999999999, 78999999999, 288899999999, 468999999999, 278999999999, 69999999999, 588889999999, 388899999999, 269999999999, 378999999999, 577999999999, 888888899999, 568999999999, 369999999999, 488899999999, 778889999999, 88999999999, 688889999999, 79999999999, 288999999999, 469999999999, 279999999999, 2288999999999, 588899999999, 388999999999, 578999999999, 379999999999, 2388999999999, 888888999999, 569999999999, 788889999999, 488999999999, 778899999999, 89999999999, 688899999999, 2778899999999, 289999999999, 2688899999999, 3788889999999, 2289999999999, 588999999999, 389999999999, 579999999999, 2588999999999, 2389999999999, 888889999999, 4488999999999, 788899999999, 489999999999, 778999999999, 99999999999, 688999999999, 2778999999999, 299999999999, 2688999999999, 3788899999999, 2299999999999, 589999999999, 399999999999, 3688999999999, 2589999999999, 2399999999999, 888899999999, 4489999999999, 788999999999, 499999999999, 779999999999, 2788999999999, 689999999999, 2779999999999, 3888899999999, 2689999999999, 3788999999999, 3499999999999, 599999999999, 5688999999999, 3689999999999, 2599999999999, 7788889999999, 888999999999, 4499999999999, 789999999999, 2888999999999, 4689999999999, 2789999999999, 699999999999, 5888899999999, 3888999999999, 2699999999999, 3789999999999, 5779999999999, 8888888999999, 5689999999999, 3699999999999, 4888999999999, 7788899999999, 889999999999, 6888899999999, 799999999999, 2889999999999, 4699999999999, 2799999999999, 22889999999999, 5888999999999, 3889999999999, 5789999999999, 3799999999999, 23889999999999, 8888889999999, 5699999999999, 7888899999999, 4889999999999, 7788999999999, 899999999999, 6888999999999, 27788999999999, 2899999999999, 26888999999999, 37888899999999, 22899999999999, 5889999999999, 3899999999999, 5799999999999, 25889999999999, 23899999999999, 8888899999999, 44889999999999, 7888999999999, 4899999999999, 7789999999999, 999999999999, 6889999999999, 27789999999999, 2999999999999, 26889999999999, 37888999999999, 22999999999999, 5899999999999, 3999999999999, 36889999999999, 25899999999999, 23999999999999, 8888999999999, 44899999999999, 7889999999999, 4999999999999, 7799999999999, 27889999999999, 6899999999999, 27799999999999, 38888999999999, 26899999999999, 37889999999999, 34999999999999, 5999999999999, 56889999999999, 36899999999999, 25999999999999, 77888899999999, 8889999999999, 44999999999999, 7899999999999, 28889999999999, 46899999999999, 27899999999999, 6999999999999, 58888999999999, 38889999999999, 26999999999999, 37899999999999, 57799999999999]

def is_sq(a):
	b = int(sqrt(a))
	return ((b-1)*(b-1) == a) or (b*b == a) or ((b+1)*(b+1) == a) 

def pretty_print(a):
	l=0
	for i in range(0,len(a)):
		for j in range(0,a[i]):
			l += 1
			if l > 0:
				print(i+1,end="")
	print()

def sum_sq_digits(a):
	ans = 0
	while a > 0:
		ans += (a%10)*(a%10)
		a = a//10
	return ans

def smaller_eq_fun(a,b):
	for i in range(0,len(a)):
		if a[i] > b[i]:
			return True
		if a[i] < b[i]:
			return False
	return True

def get_valid_beautiful_num(n,sq):
	if sq < n:
		return False
	if sq == n:
		for i in range(0,9):
			global_curr_num[i] = 0
		global_curr_num[0]=n
		return True

	ones = n-2
	nines = 0
	if sq - n > 750:
		tmp = sq - n + 2
		tmp  = max(0,tmp//80 - 5)
		ones = n - 2 - tmp
		nines = tmp

	curr_diff = 0
	for i in range(0,9):
		global_curr_num[i] = 0
	curr_tmp = [0 for i in range(0,9)]
	is_possible = False
	for i in range(0,len(last_2)):
		for j in range(0,9):
			curr_tmp[j] = 0
		curr_diff = sq - (ones + 81*nines + sum_sq_digits(last_2[i]))
		if curr_diff == 0:
			is_possible = (is_possible or True)
			curr_tmp[0] = n-nines-2
			curr_tmp[8] = nines
			curr_tmp[(last_2[i]%10)-1] += 1
			curr_tmp[(last_2[i]//10)-1] += 1
			if smaller_eq_fun(curr_tmp,global_curr_num):
				for j in range(0,9):
					global_curr_num[j] = curr_tmp[j]
			# if is_possible and ceil(sqrt(n)) + 10 > ceil(sqrt(sq)):
			# 	print(last_2[i], " ----diff === 0--- ", get_last_num(curr_tmp))
		elif curr_diff > 0 and curr_diff < len(diff_arr) and diff_arr[curr_diff] != -1:
			is_possible = (is_possible or True)
			curr_tmp[0] = n-nines-2
			curr_tmp[8]=nines
			curr_tmp[last_2[i]%10-1] += 1
			curr_tmp[last_2[i]//10-1] += 1
			diff_sq = diff_arr[curr_diff]
			while diff_sq>0 :
				curr_tmp[diff_sq%10-1] += 1
				diff_sq = diff_sq//10
				curr_tmp[0] -= 1
			if smaller_eq_fun(curr_tmp,global_curr_num):
				for j in range(0,9):
					global_curr_num[j] = curr_tmp[j]
	return is_possible

def get_last_num(a):
	ans = 0
	mul = 1
	for i in range(8,0,-1):
		for j in range(0,a[i]):
			ans += (i+1)*mul
			mul *= 10
	return ans

test_c = int(input())
curr_max_las = 0
for t in range(0,test_c):
	n = int(input())
	if n<=10:
		print(pre_[n])
		continue

	min_sq = ceil(sqrt(n))
	max_sq = floor(sqrt(81*n))+1
	is_possible = False
	curr_num = [0 for i in range(0,9)]

	for curr_sq in range(min_sq,max_sq):
		flag = get_valid_beautiful_num(n,curr_sq*curr_sq)

		if flag:
			if smaller_eq_fun(global_curr_num,curr_num):
				for i in range(0,len(curr_num)):
					curr_num[i] = global_curr_num[i]
		is_possible = (is_possible or flag)

	if is_possible:
		pretty_print(curr_num)
	else:
		while True:
			gsgs = 1
		print(-1)