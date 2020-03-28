tc = int(input())
a,b = [0 for i in range(int(1e5)+1)], [0 for i in range(int(1e5)+1)]

ans_str=""
for t in range(tc):
	str_a = input()
	str_b = input()
	n = max(len(str_a),len(str_b))
	for i in range(n):
		a[i] = (1 if i < len(str_a) and str_a[len(str_a)-1-i]=='1' else 0)
		b[i] = (1 if i < len(str_b) and str_b[len(str_b)-1-i]=='1' else 0)
	a[n]=0
	b[n]=0
	ind=0
	qu = []
	val_f = lambda a1,a2,b1,b2: ((0 if b1+b2 == 0 else 1) if (a1+a2+b1+b2 == 2) else (3 if a2+b2==1 else 2)) 
	if True:
		i=0
		while i < n + 1:
			j = i
			while j<= n and a[j]+b[j]>0:
				j+=1
			qu.append([i,j,0])
			i=j+1

	prev,l,r = 0,0,0
	mx,sm = 0,0
	while ind < len(qu):
		prev,l,r = 0,qu[ind][0],qu[ind][1]
		if r-l == 0:
			mx = max(mx,qu[ind][2])
		elif r-l == 1:
			mx = max(mx,qu[ind][2] + (0 if b[l]==0 else (1 if a[l] == 0 else 2)))
		elif r-l == 2:
			mx = max(mx,qu[ind][2] + val_f(a[l],a[l+1],b[l],b[l+1]))
		else:
			sm = 0
			for i in range(qu[ind][0],qu[ind][1]+1):
				a[i],b[i],prev = (1 if a[i]+b[i]==1 else 0), prev, (1 if a[i]+b[i]==2 else 0)
				sm += b[i]
			if sm == 0:
				mx=max(mx,qu[ind][2]+1)
			else:
				i=l
				while i < r+1:
					j=i
					while j<=r and a[j]+b[j]>0:
						j+=1
					qu.append([i,j,qu[ind][2]+1])
					i=j+1
		ind+=1
	ans_str=ans_str+str(mx)+"\n"
print(ans_str,end="")



	

