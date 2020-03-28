

tc = int(input())
for t in range(tc):
	n = int(input())
	e = [0 for i in range(n-1)]
	e.sort(reverse=True)
	gr = []
	for i in range(n):
		gr.append([])

	for i in range(n-1):
		x, y, b = list(map(int,input().split()))
		gr[x-1].append(y-1)
		gr[y-1].append(x-1)
		e[i]=b

	a = list(map(int,input().split()))
	a.sort(reverse=True)
	l,r,mid=0,n,0;
	while r-l>1:
		mid = (l+r)//2
		flag = True
		for k in range(mid,n-1):
			flag = (False if e[k] > a[k-mid+1] else flag)
		if flag:
			r = mid
		else:
			l = mid

	flag_final = True
	for i in range(l,n-1):
		flag_final = (False if e[i] > a[i-l+1] else flag)

	if flag_final:
		print(l)
	else:
		print(r)


