import math
import numpy as np

n, q = list(map(int,input().split()))

tr = []
ind_quer = []
ind_events = []
for i in range(0,n):
	tr.append([])
	ind_quer.append([])
	ind_events.append([])

for i in range(0,n-1):
	x,y = list(map(int,input().split()))
	tr[x-1].append(y-1)
	tr[y-1].append(x-1)

ini_bac_count = list(map(int,input().split()))

for i in range(0,n):
	ind_events[i].append([0, ini_bac_count[i]])



