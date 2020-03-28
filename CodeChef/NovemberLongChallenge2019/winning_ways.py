import time
start_time = time.time()
from math import ceil, floor, sqrt, log, log10
# import numpy

primes = [0 for i in range(0,int(sqrt(int(1e9))+10))]

if True:
	arr = [True for i in range(0,int(1e5))]
	arr[0] = False
	arr[1] = False

	for i in range(2,len(arr)):
		if arr[i]:
			j = i
			while j*i < len(arr):
				arr[j*i] = False
				j += 1

	j = 0
	for i in range(0,len(arr)):
		if arr[i]:
			if j < len(primes):
				primes[j] = i
				j += 1
			else:
				i = len(arr)


primes_greater_1000 = []
for i in range(0,len(primes)):
	if primes[i] > 1000:
		primes_greater_1000.append(primes[i])

search_list = []
search_list_sq = []
for i in range(0,len(primes_greater_1000)):
	tmp = primes_greater_1000[i]*primes_greater_1000[i]
	if tmp <= int(1e9):
		search_list_sq.append(tmp)
		for j in range(i+1, len(primes_greater_1000)):
			tmp = primes_greater_1000[i]*primes_greater_1000[j]
			if tmp <= int(1e9):
				search_list.append(tmp)

search_list.sort()
search_list_sq.sort()

print(len(search_list_sq), len(search_list))
print(search_list_sq[len(search_list_sq)-1])

def binary_search(li,a):
	l = 0; r = len(li)-1; mid = 0
	while r - l > 1:
		mid = (r+l)//2
		if li[mid] > a:
			r = mid
		else:
			l = mid

	return (li[l] == a) or (li[r] == a) 

t = int(input())

for tc in range(t):
	n,k = list(map(int,input().split()))
	x_arr = list(map(int,input().split()))

	num_factors = [1 for i in range(0,n)]

	ind = 0
	while primes[ind] <= 1000:
		for i in range(0,n):
			tmp = 1
			while x_arr[i]%primes[ind] == 0:
				tmp += 1
				x_arr[i] = x_arr[i]//primes[ind]
			num_factors[i] *= (tmp)
		ind += 1

	for i in range(0,n):
		if x_arr[i] < (1e6):
			if binary_search(search_list,x_arr[i]):
				num_factors[i] *= 4
			elif binary_search(search_list_sq,x_arr[i]):
				num_factors[i] *= 3
			else:
				num_factors[i] *= 2
		else:
			if x_arr[i] != 1:
				num_factors[i] *= 2

		num_factors[i] -= 1




print(time.time()-start_time)