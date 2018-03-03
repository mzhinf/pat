n = int(raw_input().strip())
now = list(str(n))
double = list(str(n * 2))
now.sort()
double.sort()
if now == double:
    print 'Yes'
else:
    print 'No'
print n * 2