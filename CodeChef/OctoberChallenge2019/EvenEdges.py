import math
import numpy as np

t = int(input())

for tc in range(0,t):
	n, m = list(map(int,input().split()))
	arr = []
	
	for i in range(0,n):
		arr.append([])
	
	for i in range(0,m):
		a,b = list(map(int,input().split()))
		arr[a-1].append(b-1)
		arr[b-1].append(a-1)

	ans = ""
	if m%2 == 0:
		ans = ans + str(1) + "\n"
		for i in range(0,n):
			ans = ans + str(1)
			if i < n - 1:
				ans = ans + " "
			else:
				ans = ans + "\n"

	else:
		flag = False
		ind = 0
		for i in range(0,n):
			if len(arr[i])%2 == 1:
				flag = True
				ind = i

		if flag:
			ans = str(2) + "\n"

			for i in range(0,n):
				if i != ind:
					ans = ans + str(1)
				else:
					ans = ans + str(2)

				if i < n - 1:
					ans = ans + " "
				else:
					ans = ans + "\n"
		else:
			ans = str(3) + "\n"
			ind = 0
			while len(arr[ind]) == 0:
				ind += 1

			for i in range(0,n):
				if i == ind:
					ans = ans + str(2)
				else:
					if i == arr[ind][0]:
						ans = ans + str(3)
					else:
						ans = ans + str(1)

				if i < n - 1:
					ans = ans + " "
				else:
					ans = ans + "\n"

	print(ans,end="")


