def least_rotation(S):
    S += S  # Concatenate string to it self to avoid modular arithmetic
    f = [-1] * len(S)  # Failure function
    k = 0  # Least rotation of string found so far
    for j in range(1, len(S)):
        sj = S[j]
        i = f[j - k - 1]
        while i != -1 and sj != S[k + i + 1]:
            if sj < S[k + i + 1]:
                k = j - i - 1
            i = f[i]
        if sj != S[k + i + 1]:  # if sj != S[k+i+1], then i == -1
            if sj < S[k]:  # k+i+1 = k
                k = j
            f[j - k] = -1
        else:
            f[j - k] = i + 1
    return k

test = int(input())
for tc in range(test):
    l,st = input().split()
    l=int(l)
    if l==1:
        kk = least_rotation(st)
        ln = len(st)
        mt = ""
        for i in range(len(st)):
            mt+=str(st[(kk+i)%ln])
        print(mt)
    else:
        lst = []
        for i in range(len(st)):
            lst.append(st[i])
        lst.sort()
        mt = ""
        for i in range(len(lst)):
            mt+=str(lst[i])
        print(mt)