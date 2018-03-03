#input n, k
n, k = map(int, raw_input().strip().split())
#input infomation
infos = []
for i in range(n):
	cin = map(str, raw_input().strip().split())
	time = map(int, cin[0].split(':'))
	info = [time, time[0] * 60 * 60 + time[1] * 60 + time[2], int(cin[1])]
	infos.append(info)
infos.sort(key = lambda x : x[1])
#inport queue
import Queue
#create a priority queue
service = Queue.PriorityQueue()
waitTime = 0
for i in range(k):#insert start work time
    service.put(8 * 60 * 60)
for info in infos:
    endTime = service.get()
    if info[1] > 17 * 60 * 60:#over service time
        n -= 1
        service.put(endTime)
    else:
        if endTime > info[1]:#still service
            waitTime +=  endTime - info[1]
            service.put(endTime + info[2] * 60)
        else:#end service
            service.put(info[1] + info[2] * 60)
if n == 0:
    print '0.0'
else:
    print "%.1f" % ((waitTime / 60.0) / n)