num, n = map(int, raw_input().strip().split())
i = 0
while i < n:
    reverse = int(str(num)[::-1])
    if num == reverse: # num, i
        break
    else:
        num += reverse
    i += 1
print num
print i

'''
    reverse str
    1.
    word[::-1]
    2.
    L = list(word)
    L.reverse()
    word = "".joib(L)
'''