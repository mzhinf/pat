#素数测试 O(√n)
def is_prime(num):
    if num < 2: return False
    i = 2
    while i * i <= num:
        if num % i == 0:
            return False
        i += 1
    return True
#十进制数num按照radix进制倒转
def reversible(num, radix):
    res = 0
    while num > 0:
        res = res * radix + num % radix
        num /= radix
    return res

while True:
    cin = map(int, raw_input().strip().split())
    if len(cin) == 1:
        exit(0)
    num, radix = cin
    if is_prime(num) and is_prime(reversible(num, radix)):
        print "Yes"
    else:
        print "No"