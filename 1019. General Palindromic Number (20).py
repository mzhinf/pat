#input n, b
n, b = map(int, raw_input().strip().split())
#if n == 0
if n == 0:
    print 'Yes\n0'
else:
    #n in base b
    L = []
    while n > 0:
        L.append(str(n % b))
        n /= b
    L.reverse()
    #judge is palindromic number
    half = len(L) / 2
    isYes = True
    for i in range(half):
        if L[i] != L[-i - 1]:#0~n-1 -1~-n
            isYes = False
            break
    #output answer
    if isYes:
        print 'Yes'
    else:
        print 'No'
    div = ' '
    print div.join(L)