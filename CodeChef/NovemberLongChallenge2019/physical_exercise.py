import time
import math
import numpy as np

start_time = time.time()

tc = int(input())
mod = int(1e9)+1

ax = [0 for i in range(0,5000)]
ay = [0 for i in range(0,5000)]
ab_xy = [0.0 for i in range(0,5000)]
ab_min = [0.0 for i in range(0,5000)]

cx = [0 for i in range(0,5000)]
cy = [0 for i in range(0,5000)]
cd_xy = [0.0 for i in range(0,5000)]
cd_min = [0.0 for i in range(0,5000)]

ex = [0 for i in range(0,5000)]
ey = [0 for i in range(0,5000)]

ans_str = ""
for t in range(tc):
	x,y = list(map(int,input().split()))
	n,m,k = list(map(int,input().split()))
	a = list(map(int,input().split()))
	for i in range(0,n):
		ax[i] = a[2*i]
		ay[i] = a[2*i+1]

	c = list(map(int,input().split()))
	for i in range(0,m):
		cx[i] = c[2*i]
		cy[i] = c[2*i+1]
		
	e = list(map(int,input().split()))
	for i in range(0,k):
		ex[i] = e[2*i]
		ey[i] = e[2*i+1]

	dist = 0
	for i in range(0,n):
		ab_xy[i] = math.sqrt((x-ax[i])*(x-ax[i]) + (y-ay[i])*(y-ay[i]))
		dist = 2.0*(mod*mod)
		for j in range(0,k):
			dist = min(dist,math.sqrt((ax[i]-ex[j])*(ax[i]-ex[j]) + (ay[i]-ey[j])*(ay[i]-ey[j])))
		ab_min[i] = dist

	for i in range(0,m):
		cd_xy[i] = math.sqrt((x-cx[i])*(x-cx[i]) + (y-cy[i])*(y-cy[i]))
		dist = 2*mod*mod
		for j in range(0,k):
			dist = min(dist,math.sqrt((cx[i]-ex[j])*(cx[i]-ex[j]) + (cy[i]-ey[j])*(cy[i]-ey[j])))
		cd_min[i] = dist

	ans = 3.0*mod*mod
	tmp = 0.0
	for i in range(0,n):
		for j in range(0,m):
			tmp = min(ab_xy[i] + cd_min[j],cd_xy[j] + ab_min[i]) + math.sqrt((ax[i]-cx[j])*(ax[i]-cx[j]) + (ay[i]-cy[j])*(ay[i]-cy[j]))
			ans = min(ans,tmp)

	ans_str = ans_str + str(ans) + "\n"

print(ans_str,end="")

print("--- %s seconds ---" % (time.time() - start_time))
		