# class Heap:
# 	arr = None
# 	heap_size = None
# 	max_size = None
	
# 	def __init__(self):
# 		self.arr = []
# 		self.heap_size = 0
# 		self.max_size = 0

# 	def parent(self,i):
# 		return (i-1)//2

# 	def size(self):
# 		return self.heap_size
	
# 	def empty(self):
# 		return (True if self.heap_size == 0 else False)

# 	# < is equivalent to min_heap
# 	# > is equivalent to max_heap
# 	def true_func(self,i,j):
# 		if not(i < self.heap_size and j < self.heap_size):
# 			raise RuntimeError("Index Out of Bound")
# 		return (True if self.arr[i] < self.arr[j] else False)

# 	def insert(self,k):
# 		if self.max_size == self.heap_size:
# 			self.arr.append(k)
# 			self.max_size += 1
# 			self.heap_size += 1
# 		else:
# 			self.arr[self.heap_size-1]=k
# 			self.heap_size += 1

# 		if self.heap_size>1:
# 			self.arr[0],self.arr[self.heap_size-1] = self.arr[self.heap_size-1],self.arr[0]
# 			i = self.heap_size-1
# 			while i!=0 and self.true_func(i,self.parent(i)):
# 				self.arr[i],self.arr[self.parent(i)] = self.arr[self.parent(i)],self.arr[i]
# 				i = self.parent(i)

# 	def top(self):
# 		if self.empty():
# 			raise RuntimeError("Heap is empty")
# 		return self.arr[0]

# 	def pop(self):
# 		if self.empty():
# 			raise RuntimeError("Heap is empty")

# 		self.arr[0]=self.arr[self.heap_size-1]
# 		self.heap_size -= 1
# 		if not(self.empty()):
# 			self.heapify(0)

# 	def heapify(self,i):
# 		l = 2*i+1
# 		r = 2*i+2
# 		next_ind = i
# 		if(l < self.heap_size and self.true_func(l,next_ind)):
# 			next_ind = l

# 		if(r < self.heap_size and self.true_func(r,next_ind)):
# 			next_ind = r

# 		if(next_ind != i):
# 			self.arr[i],self.arr[next_ind] = self.arr[next_ind],self.arr[i]
# 			self.heapify(next_ind)

def solve():
	tc = int(input())
	ans_str = ""
	s,e = [0 for i in range(int(1e5)+10)], [0 for i in range(int(1e5)+10)]
	inp_a,inp_b = 0,0
	for t in range(tc):
		n = int(input())
		arr = []
		for i in range(n):
			inp_a,inp_b = list(map(int,input().split()))
			s[i]=inp_a
			e[i]=inp_b
		s[:n]=sorted(s[:n])
		e[:n]=sorted(e[:n])

		ans = int(1e7)
		curr_s,curr_e = 0,0
		for p in s:
			x,y = 0,n
			if p >= e[0]:
				while curr_e+1 < n and e[curr_e+1]<=p:
					curr_e += 1
				x = curr_e+1

			if p >= s[0]:
				while curr_s+1<n and s[curr_s+1]<=p:
					curr_s += 1
				y = n-curr_s-1

			if x>0 and y>0:
				ans = min(n-x-y,ans)

		curr_s,curr_e = 0,0
		for p in e:
			x,y = 0,n
			if p >= e[0]:
				while curr_e+1 < n and e[curr_e+1]<=p:
					curr_e += 1
				x = curr_e+1

			if p >= s[0]:
				while curr_s+1<n and s[curr_s+1]<=p:
					curr_s += 1
				y = n-curr_s-1

			if x>0 and y>0:
				ans = min(n-x-y,ans)

		if ans >= n-1:
			ans = -1
		ans_str = ans_str + str(ans) + "\n"
	print(ans_str,end="")

solve()