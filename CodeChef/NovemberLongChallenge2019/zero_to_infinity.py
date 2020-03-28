import math

tc = int(input())
def is_vowel(a):
	return (a == 'a') or (a == 'e') or (a == 'i') or (a == 'o') or (a == 'u')


ans_str = ""
for t in range(tc):
	n = 0; m = 0
	xa = []; xb = []; fa = []; fb = []
	for i in range(0,26):
		xa.append(0)
		xb.append(0)
		fa.append(0)
		fb.append(0)

	l = int(input())
	ctr = [0 for i in range(0,26)]
	for i in range(l):
		tmp = input()
		flag = True
		if (len(tmp) == 2) and not(is_vowel(tmp[0])) and not(is_vowel(tmp[1])):
			flag = False
		else:
			for i in range(0,len(tmp)-2):
				if not(is_vowel(tmp[i])) and (not(is_vowel(tmp[i+1])) or not(is_vowel(tmp[i+2]))):
					flag = False
					i = len(tmp)
			if flag and not(is_vowel(tmp[len(tmp)-2])) and not(is_vowel(tmp[len(tmp)-1])):
				flag = False

		for i in range(0,26):
			ctr[i] = 0

		for i in range(0,len(tmp)):
			ctr[int(ord(tmp[i])-ord('a'))] += 1

		if flag:
			n += 1
			for i in range(0,26):
				xa[i] += int(ctr[i]>0)
				fa[i] += ctr[i]
		else:
			m += 1
			for i in range(0,26):
				xb[i] += int(ctr[i]>0)
				fb[i] += ctr[i]

	ans1 = 0; ans2 = 0; ans3 = 0
	for i in range(0,26):
		if(xa[i] != 0):
			ans1 += math.log(1.0*xa[i],10.0)
		if(xb[i] != 0):
			ans1 -= math.log(1.0*xb[i],10.0)
		if(fa[i] != 0):
			ans2 += math.log(1.0*fa[i],10.0)
		if(fb[i] != 0):
			ans3 += math.log(1.0*fb[i],10.0)

	min_mn = min(m,n)
	ans = ans1 + min_mn*(ans3-ans2) + (m-min_mn)*ans3 - (n-min_mn)*ans2
	if(ans > 7):
		ans_str = ans_str + "Infinity\n"
	else:
		ans_str = ans_str + str(pow(10,ans)) + "\n"

print(ans_str,end="")

