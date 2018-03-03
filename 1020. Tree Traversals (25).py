#postorder left:[0,i-1] right:[i,n-2] root:n-1
#inorder   left:[0,i-1] root:i right:[i+1,n-1]
def post_in(n, postorder, inorder):
    global count
    count += 1
    #find root
    root = postorder[n - 1]
    pos = count
    i = 0
    while inorder[i] != root and i < n:
        i += 1
    #del root
    value[pos] = root
    #left
    if i != 0:
        left[pos] = post_in(i, postorder[0:i], inorder[0:i])
    else:
        left[pos] = -1
    #right
    if n - 1 - i != 0:
        right[pos] = post_in(n - 1 - i, postorder[i:-1], inorder[i + 1:])
    else:
        right[pos] = -1
    return pos
import Queue
def levelOrder(start):
    q = Queue.Queue()
    q.put(start)
    while True:
        pos = q.get()
        if left[pos] != -1:
            q.put(left[pos])
        if right[pos] != -1:
            q.put(right[pos])
        if q.empty():
            print value[pos]
            break
        else:
            print value[pos],
#input n
n = int(raw_input().strip())
#input postorder and inorder traversal sequences
postorder = map(int, raw_input().strip().split())
inorder = map(int, raw_input().strip().split())
value = [0] * n # point value
left = [0] * n # left tree
right = [0] * n # right tree
count = -1
post_in(n, postorder, inorder)
levelOrder(0)