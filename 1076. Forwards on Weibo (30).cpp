#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> node[1005];
vector<int>::iterator it;
bool visit[1005];
queue<int> q, tq;

int main(){
    int n, l, num, v, sum, tl;
    scanf("%d%d", &n, &l);
    for(int i = 1; i <= n; i++){
        scanf("%d", &num);
        while(num--){
            scanf("%d", &v);//i 关注 v => i 能转发 v 微博
            node[v].push_back(i);//v 的微博能被 i 转发
        }
    }
    //query
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        scanf("%d", &v);
        //init
        tl = l;//控制循环次数不超过 l
        sum = 0;
        memset(visit, 0, sizeof(visit));
        tq.push(v);
        visit[v] = true;
        while(tl-- && !tq.empty()){
            q = tq;
            tq = queue<int>();
            while(!q.empty()){
                int t = q.front(); q.pop();
                for(it = node[t].begin(); it != node[t].end(); it++){
                    v = *it;
                    if(!visit[v]){
                        tq.push(v);
                        visit[v] = true;
                        sum++;
                    }
                }
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
