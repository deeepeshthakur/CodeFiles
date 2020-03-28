import time
start_time = time.time()

l = []
for i in range(1,int(1e7)):
	l.append(i)

print(time.time()-start_time)