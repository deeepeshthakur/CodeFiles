t = int(input())
for tc in range(t):
	n = int(input())
	a = int(input())
	s = 10**n
	print(2*s+a, flush=True)
	b = int(input())
	print(s-b, flush=True)
	c = int(input())
	print(s-c, flush=True)

	ans = int(input())
	if(ans==-1):
		break;