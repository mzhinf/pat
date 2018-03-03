#include <cstdio>
#include <queue>

using namespace std;

vector<int> son[100005];
vector<int>::iterator it;
int product[100005];
queue<int> q, tq;

int main(){
    int N, n, v;
    double P, r;
    scanf("%d%lf%lf", &N, &P, &r);
    for(int i = 0; i< N; i++){
        scanf("%d", &n);
        if(n == 0){
            scanf("%d", &v);
            product[i] = v;
        } else {
            while(n--){
                scanf("%d", &v);
                son[i].push_back(v);
            }
        }
    }
    double res = 0, p = P;
    tq.push(0);
    while(!tq.empty()){
        q = tq;
        tq = queue<int>();
        while(!q.empty()){
            v = q.front(); q.pop();
            if(son[v].size() == 0){//retailers
                res += product[v] * p;
                //printf("%.2lf\n", res);
            } else {
                for(it = son[v].begin(); it != son[v].end(); it++){
                    tq.push(*it);
                    //printf("push:%d\n", *it);
                }
            }
        }
        p = p * (100 + r) / 100;
    }
    printf("%.1lf\n", res);
    return 0;
}
