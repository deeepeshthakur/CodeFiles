import sys
orig_stdout = sys.stdout
f = open('outputPy.txt', 'w')
sys.stdout = f

def closed_range(start, stop, step=1):
  dir = 1 if (step > 0) else -1
  return range(start, stop + dir, step)

s = []
pow2 = []

def bCoeff( n, k):
  if( n < k):
    return 0

  if(n == k | k == 0):
    return 1

  return  s[n]/(s[k]*s[n - k])


def solveF( n, k):
  # n, k = (int(x) for x in raw_input().split())
  div = 1000000007
  if n < k:
    return 0

  if n == k:
    return 2

  ans = 0
  for i in closed_range( 0, k - 1):
    ans += pow2[k - i]*bCoeff( k - 1, i)*bCoeff( n + 1 - k, n + 1 + i - 2*k)

  ans %= div
  return ans


testC = int(raw_input())
s.append(1)
for i in closed_range( 1, 1001):
  s.append( i * s[i - 1])

pow2.append(1)
for i in closed_range( 1, 1000):
  pow2.append( 2 * pow2[i - 1])

if testC > 0:
  # for x in closed_range( , 100):
  #   for y in closed_range( 1, 100):
  #     if(x >= y):
  x, y = (int(x) for x in raw_input().split())
  print x, y, solveF( x, y)

sys.stdout = orig_stdout
f.close()