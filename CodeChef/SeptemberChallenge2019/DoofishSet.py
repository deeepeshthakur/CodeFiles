import numpy as np
import math

n, m = list(map(int,input().split()))

gr = []
visited = []
for i in range(0,n):
	gr.append([])
	visited.append(True)

edges = []
for i in range(0,m):
	a, b = list(map(int, input().split()))
	a = a - 1
	b = b - 1
	edges.append((a,b))
	edges.append((b,a))

edges.sort(key = lambda x : x[1])

for i in range(0,2*m):
	gr[edges[i][0]].append(edges[i][1])

groups = []
arr = []
groups_num = []
for i in range(0,n):
	arr.append(i)
	groups_num.append(0)

possible = True
flag = True
while(flag):
	nn = len(arr)
	arr1 = []
	ln = len(gr[arr[0]])
	for i in range(0,ln):
		if visited[gr[arr[0]][i]]:
			arr1.append(gr[arr[0]][i])

	arr2 = []
	j = 0
	ln = len(arr1)
	for i in range(0,nn):
		if j < ln and arr1[j] == arr[i]:
			j += 1
		else:
			arr2.append(arr[i])

	node_set = set(arr1)

	for i in range(0,len(arr2)):
		lln = len(gr[arr2[i]])
		tmp = 0
		for j in range(0,lln):
			if visited[gr[arr2[i]][j]]:
				tmp += 1
				node_set.add(gr[arr2[i]][j])
		possible = bool(possible and len(arr1) == tmp)

	possible = bool(possible and len(node_set) == len(arr1))

	for i in range(0,len(arr2)):
		visited[arr2[i]] = False

	if possible:
		groups.append(arr2)
		arr = arr1
	flag = bool( len(arr) > 0 and possible)


k = 0

def f1(l,r,dp_table,height):
	global k
	if r > l:
		mid = (l + r)//2
		for i in range(l,mid+1):
			dp_table[height][i] = 1

		for i in range(mid+1,r+1):
			dp_table[height][i] = 0

		f1(l,mid,dp_table,height+1)
		f1(mid+1,r,dp_table,height+1)
		k = max(k,height)

if possible:
	n_groups = len(groups)
	for i in range(0,n_groups):
		gr_ln = len(groups[i])
		for j in range(0,gr_ln):
			groups_num[groups[i][j]] = i

	div = 1
	ctr = 10
	while n_groups//div > 0:
		div *= 2
		ctr += 1
	dp_table = []
	
	for i in range(0,ctr):
		arr3 = []
		for j in range(0,n_groups):
			arr3.append(1)
		dp_table.append(arr3)

	layer = 0
	f1(0,n_groups - 1,dp_table,layer)

	if n_groups > 1:
		k += 1
		print(k)
		ans = ""
		for i in range(0,k):
			for j in range(0,n):
				ans = ans + str(dp_table[i][groups_num[j]])
			ans = ans + "\n"
		print(ans,end="")
	else:
		print(0)
else:
	print(-1)





