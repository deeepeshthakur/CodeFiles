k = int(1e9)*int(1e9)

st = 10
en = 0
sum_k = 45
curr = 9

def dig(a):
	ans = 0;
	while a>0:
		ans += 1
		a = a//10
	return ans

while sum_k < k :
	en = st*10 - 1
	digits = dig(st)
	curr += digits
	next_curr = curr + (en-st)*digits
	sum_k += ((en-st+1)*(curr+next_curr))//2
	curr = next_curr
	print(st,en,sum_k,curr)
	st = en+1

