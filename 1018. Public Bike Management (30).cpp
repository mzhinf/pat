#include <cstdio>
#include <cstring>
#include <vector>
#define MAX_N 505

using namespace std;

const int inf = 0x3f3f3f3f;

int cost[MAX_N][MAX_N];//i -> j 距离 初始化inf
bool used[MAX_N];//改点是否被使用 初始化false
int d[MAX_N];//0 -> i 的最短距离 初始化inf
vector<int> pre[MAX_N];//i 的前驱 初始化-1
int value[MAX_N];//i 站点此时有多少bike
vector<int> path, tpath;

int need, over, minNeed, minOver;
void dfs(int v){
    if(v == 0){
        tpath.push_back(v);
        need = over = 0;
        for(int i = tpath.size() - 1; i >= 0; i--){
            int id = tpath[i];
            if(value[id] >= 0){
                over += value[id];
            } else {
                if(over >= -value[id]){
                    over += value[id];
                } else {
                    need += -value[id] - over;
                    over = 0;
                }
            }
        }
        if(need < minNeed){
            minNeed = need;
            minOver = over;
            path = tpath;
        } else if (need == minNeed && over < minOver){
            minOver = over;
            path = tpath;
        }
        tpath.pop_back();
        return ;
    }
    tpath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) dfs(pre[v][i]);
    tpath.pop_back();
}

void dij(int p, int n){//p dij终点 n dij大小
    //init
    for(int i = 0; i <= n; i++){
        used[i] = false;
        d[i] = inf;
    }
    //start dij
    d[0] = 0;
    while(true){
        int v = -1;
        //choice min
        for(int i = 0; i <= n; i++){
            if(!used[i] && (v == -1 || d[i] < d[v])) v = i;
        }
        if(v == -1 || v == p) break;
        //use v extend
        used[v] = true;
        for(int i = 0; i <= n; i++){
            if(d[i] > d[v] + cost[v][i]){//0 -> v -> i 较短 更新
                d[i] = d[v] + cost[v][i];
                pre[i].clear();
                pre[i].push_back(v);
            } else if(d[i] == d[v] + cost[v][i]){
                pre[i].push_back(v);
            }
        }
    }
}

int main(){
    int c, n, p, m, st, ed, v;
    scanf("%d%d%d%d", &c, &n, &p, &m);
    memset(cost, 0x3f, sizeof(cost));
    for(int i = 1; i <= n; i++){
        scanf("%d", &value[i]);
        value[i] -= c / 2;
    }
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &st, &ed, &v);
        cost[st][ed] = v;
        cost[ed][st] = v;
    }
    dij(p, n);
    minNeed = minOver = inf;
    dfs(p);
    printf("%d 0", minNeed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minOver);
    return 0;
}
/*
10 4 4 5
6 7 6 0
0 1 1
0 2 1
1 3 1
2 3 1
3 4 1

2 0->2->3->4 0

*/
