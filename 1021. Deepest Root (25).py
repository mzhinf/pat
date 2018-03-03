import Queue
def levelOrder(start):
    vis = [False] * (n + 1)
    tq = Queue.Queue()
    tq.put(start)
    vis[start] = True
    res = []
    while not tq.empty():
        q = tq
        tq = Queue.Queue()
        res = []
        while not q.empty():
            pos = q.get()
            res.append(pos)
            for i in son[pos]:
                if not vis[i]:
                    tq.put(i)
                    vis[i] = True
    return res
def isTree():
    vis = [False] * (n + 1)
    res = 0
    for i in range(1, n + 1):
        if vis[i]:
            continue
        vis[i] = True
        res += 1
        q = Queue.Queue()
        q.put(i)
        while not q.empty():
            pos = q.get()
            for j in son[pos]:
                if not vis[j]:
                    q.put(j)
                    vis[j] = True
    return res

#input n
n = int(raw_input().strip())
#input graph
son = [[] for i in range(n + 1)]
for i in range(n - 1):
    a, b = map(int, raw_input().strip().split())
    son[a].append(b)
    son[b].append(a)
#judge is tree
components = isTree()
if components != 1:
    print 'Error: %d components' % components
else:
    res = levelOrder(1)
    res.extend(levelOrder(res[0]))
    res = list(set(res)) # delete duplicate elements
    res.sort()
    res = map(str, res) # int list -> str list
    print '\n'.join(res) # '\n' divide list