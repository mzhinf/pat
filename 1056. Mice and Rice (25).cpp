#include <cstdio>
#include <queue>

using namespace std;

int value[1005];
int out[1005];
queue<int> q, tq;

int main(){
    int np, ng, v;
    scanf("%d%d", &np, &ng);
    for(int i = 0; i < np; i++){
        scanf("%d", &value[i]);
    }
    for(int i = 0; i < np; i++){
        scanf("%d", &v);
        tq.push(v);
    }
    int n = np;
    while(true){
        int _rank = (n + ng - 1) / ng + 1;
        q = tq;
        tq = queue<int>();
        while(!q.empty()){
            int smax = -1;
            for(int i = 0; !q.empty() && i < ng; i++){
                int temp = q.front(); q.pop();
                if(smax == -1) smax = temp;
                else if(value[smax] < value[temp]){
                    out[smax] = _rank;
                    smax = temp;
                } else {
                    out[temp] = _rank;
                }
            }
            tq.push(smax);
        }
        n = _rank - 1;
        //printf("%d\n", n);
        if(n == 1){
            int temp = tq.front(); tq.pop();
            out[temp] = 1;
            break;
        }
    }
    for(int i = 0; i < np; i++){
        printf("%d%c", out[i], i + 1 == np ? '\n' : ' ');
    }
    return 0;
}
