testc = int(input())

ans_str = ""
for i in range(testc):
	n,k = list(map(int,input().split()))
	a = list(map(int,input().split()))
	sm = sum(a)
	ans = sm%k

	ans_str = ans_str + str(ans) + "\n"

print(ans_str,end="")