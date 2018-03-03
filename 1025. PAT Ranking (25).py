#input n, info
n = int(raw_input().strip())
L = []
rank = [0] * (n + 1) # rank
record = [1] * (n + 1) # recond grade
jump = [1] * (n + 1) # recond jump num
num = 0
for i in range(n):
    k = int(raw_input().strip())
    num += k
    for j in range(k):
        cin = raw_input().strip().split()
        number = cin[0] # number use str
        grade = int(cin[1])
        L.append((number, -grade, i + 1))
L.sort(key = lambda item : (item[1], item[0]))
#standard output
print num
for item in L:
    #final_rank record[0] rank[0]
    if record[0] != item[1]:
        record[0] = item[1]
        rank[0] += jump[0]
        jump[0] = 1
    else:
        jump[0] += 1
    #local_rank record[item[2]] rank[item[2]]
    if record[item[2]] != item[1]:
        record[item[2]] = item[1]
        rank[item[2]] += jump[item[2]]
        jump[item[2]] = 1
    else:
        jump[item[2]] += 1
    #output registration_number final_rank location_number local_rank
    print '%s %d %d %d' % (item[0], rank[0], item[2], rank[item[2]])