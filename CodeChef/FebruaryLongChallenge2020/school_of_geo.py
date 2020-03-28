testc = int(input())
ans_str=""
for i in range(testc):
	n = int(input())
	a = list(map(int,input().split()))
	b = list(map(int,input().split()))

	a.sort()
	b.sort()
	ans=0
	for i in range(len(a)):
		ans = ans+min(a[i],b[i])

	ans_str=ans_str+str(ans)+"\n";

print(ans_str,end="")
