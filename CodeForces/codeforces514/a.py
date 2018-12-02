def f(l, result, gcd):
        if l == 1:
                result.append(1*gcd)
        elif l == 2:
                result.append(1*gcd)
                result.append(2*gcd)
        elif l == 3:
                result.append(1*gcd)
                result.append(1*gcd)
                result.append(3*gcd)
        else:
                if l % 2 == 0:
                        for i in xrange(l/2):
                                result.append(1*gcd)
                        gcd *= 2
                        f(l/2, result, gcd)
                else:
                        for i in xrange((l+1)/2):
                                result.append(1*gcd)
                        gcd *= 2
                        f((l-1)/2, result, gcd)
        return result
n = int(raw_input())
r = f(n, [], 1)
for i in xrange(len(r)):
	print r[i],
