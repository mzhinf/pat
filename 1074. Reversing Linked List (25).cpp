/*
    最后一个1分的case无法通过，原因是没有考虑到输入的N个节点，
    有某个或某些不在链表上，所以最后要输出的总的节点数小于N。
*/
#include <cstdio>
#include <stack>

using namespace std;

int snext[100005];
int v[100005];
stack<int> s;

int main(){
    int st_id, n, k, add, t_v, t_next;
    scanf("%d%d%d", &st_id, &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &add, &t_v, &t_next);
        snext[add] = t_next;
        v[add] = t_v;
    }
    //先计算n 将不存在链表的结点排除
    int head = st_id, t_n;
    for(t_n = 1; t_n <= n && snext[head] != -1; t_n++) head = snext[head];
    n = t_n;
    //-----
    head = st_id;
    bool flag = false;
    while(n >= k){
        for(int i = 0; i < k; i++){
            s.push(head);
            head = snext[head];
        }
        for(int i = 0; i < k; i++){
            t_v = s.top(); s.pop();
            if(flag) printf("%05d\n", t_v);
            else flag = true;
            printf("%05d %d ", t_v, v[t_v]);
        }
        n -= k;
    }
    for(int i = 0; ; i++){
        if(i == n){
            printf("-1\n");
            break;
        }
        if(flag)printf("%05d\n", head);
        else flag = true;
        printf("%05d %d ", head, v[head]);
        head = snext[head];
    }
    return 0;
}
/*
in:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
out:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1

in:
00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
out:
33218 3 12309
12309 2 00100
00100 1 68237
68237 6 99999
99999 5 00000
00000 4 -1

00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 -1
99999 5 68237
12309 2 33218
*/
