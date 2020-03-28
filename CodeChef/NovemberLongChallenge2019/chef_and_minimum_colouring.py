tc = int(input())

st = [-1 for i in range(0,3*int(1e5))]

ans_str = ""

def search_tree():
	global st
	return st[0]

def edit_query(val,index,l,r,st_index):
	global st

	if (l > r):
		return -1

	if (l == r) and (index == r):
		st[st_index] = val
		return st[st_index]

	if (index >= l) and (index <= r):
		st[st_index] = max(edit_query(val,index,l,(l+r)//2,2*st_index+1),edit_query(val,index,(l+r)//2+1,r,2*st_index+2))
	
	return st[st_index]

for t in range(tc):
	n,m = list(map(int,input().split()))
	arr = list(map(int,input().split()))

	tup = []
	tot_ele = [0 for i in range(0,m)]

	tmp = 0
	for i in range(0,n):
		tot_ele[tmp] += 1
		tup.append((arr[i],tmp))
		tmp = (tmp + 1)%m

	tup.sort(key = lambda x: x[0])

	ans = abs(tup[n-1][0] - tup[0][0])

	if m < 20:
		lm = [int(1e6) for i in range(0,m)]
		for i in range(n-1,-1,-1):
			lm[tup[i][1]] = i
			mx = 0
			for j in range(0,m):
				mx = max(mx,lm[j])
			
			if mx < n:
				ans = min(ans,abs(tup[i][0] - tup[mx][0]))
	else:
		for i in range(0,2*m+1):
			st[i] = int(1e6)

		for i in range(n-1,-1,-1):
			ret_val = edit_query(i,tup[i][1],0,m-1,0)
			mx = search_tree()
			if(mx < n):
				ans = min(ans,abs(tup[i][0] - tup[mx][0]))
	ans_str = ans_str + str(ans) + "\n"

print(ans_str,end="")