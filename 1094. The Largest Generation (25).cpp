#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> son[105];//1 - 100
vector<int>::iterator it;
int high[105];
queue<int> q, tq;

int main(){
    int n, m, f, s, snum;
    memset(high, 0, sizeof(high));
    scanf("%d%d", &n, &m);
    while(m--){
        scanf("%d%d", &f, &snum);
        while(snum--){
            scanf("%d", &s);
            son[f].push_back(s);
        }
    }
    int th = 0, smax = -1, sh = -1, tnum;
    tq.push(1);
    while(!tq.empty()){
        th++;
        tnum = 0;
        q = tq;
        tq = queue<int>();
        while(!q.empty()){
            f = q.front(); q. pop();
            high[f] = th;
            for(it = son[f].begin(); it != son[f].end(); it++){
                tq.push(*it);
            }
            tnum++;
        }
        if(smax < tnum){
            smax = tnum;
            sh = th;
        }
    }
    printf("%d %d\n", smax, sh);
    return 0;
}
