n = int(raw_input().strip())
L = []
for i in xrange(n):
    cin = raw_input().strip().split()
    time = map(int, cin[0].split(':'))
    allTime = time[0] * 60 * 60 + time[1] * 60 + time[2]
    playTime = int(cin[1])
    isVip = True if cin[2] == '1' else False
    info = [allTime, cin[0], playTime, isVip]
    L.append(info)
L.sort(key = lambda info : info[0])
k, m = map(int, raw_input().strip().split())
vipNumbers = set(map(int, raw_input().strip().split()))
#inport queue
import Queue
#create a priority queue
service = Queue.PriorityQueue()
for i in range(k):#insert start work time
    service.put(8 * 60 * 60)
