'''
    使用str存储id 以防止前导0
'''
#input n infos
n = int(raw_input().strip())
infos = []
for i in range(n):
    info = []
    for i in range(6):
        info.append(raw_input().strip())
    infos.append(info)
infos.sort(key = lambda x : x[0])
#create dictionary
dictionary = [{} for i in range(6)]
for info in infos:
    bookId = info[0]
    for i in range(1, 6):
        if i == 3:
            words = map(str, info[i].split())
        else:
            words = [info[i]]
        for word in words:
            if word in dictionary[i]:
                dictionary[i][word].append(bookId)
            else:
                dictionary[i][word] = [bookId]
#input m query
m = int(raw_input().strip())
for i in range(m):
    cin = map(str, raw_input().strip().split(': '))
    print ': '.join(cin)
    queryId = int(cin[0])
    queryWord = cin[1]
    if queryWord in dictionary[queryId]:
        print '\n'.join(dictionary[queryId][queryWord])
    else:
        print 'Not Found'