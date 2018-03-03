/**
    *注意不要滥用set map等容器 毕竟O(logn)
*/
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

set<int> sset[55];
set<int>::iterator sit;

int main(){
    int n, m, a, b, v;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &m);
        for(int j = 1; j <= m; j++){
            scanf("%d", &v);
            sset[i].insert(v);
        }
    }
    scanf("%d", &m);
    for(int j = 0; j < m; j++){
        scanf("%d%d", &a, &b);
        int len = 0, common = 0;
        for(sit = sset[a].begin(); sit != sset[a].end(); sit++){
            if(sset[b].find(*sit) != sset[b].end()) common++;
        }
        len = sset[a].size() + sset[b].size() - common;
        //printf("%d %d\n", len, common);
        printf("%.1lf%%\n", (double)common / len  * 100);
    }
    return 0;
}
