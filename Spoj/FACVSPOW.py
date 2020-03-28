import math
import numpy as np

ans_list = []
ind = 0
fac_Val = 1.0

for i in range(2,int(1e6)+1):
	fac_Val = fac_Val/(np.power(i/(i-1),ind))
	while(fac_Val <= 1):
		ind = ind + 1
		fac_Val = fac_Val*(ind/i)
	ans_list.append(ind)

# for i in range(0,len(ans_list)):
# 	print(i+2, ans_list[i])

# print(len(ans_list))

t = int(input())
ans_str = ""
for tc in range(0,t):
	a = int(input())
	ans_str = ans_str + str(ans_list[a-2]) + "\n"

print(ans_str,end="")
