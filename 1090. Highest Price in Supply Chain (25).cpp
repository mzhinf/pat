#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> son[100005];
vector<int>::iterator it;
queue<int> q, tq;

int main(){
    int n, fa, st;
    double p, r;
    scanf("%d%lf%lf", &n, &p, &r);
    for(int i = 0; i < n; i++){
        scanf("%d", &fa);
        if(fa != -1) son[fa].push_back(i);
        else st = i;
    }
    double h = p;
    int num = 1, tnum;
    //²ã´Î±éÀú
    tq.push(st);
    while(!tq.empty()){
        q = tq;
        tq = queue<int>();
        tnum = 0;
        while(!q.empty()){
            int t = q.front(); q.pop();
            for(it = son[t].begin(); it != son[t].end(); it++){
                tq.push(*it);
            }
            tnum += son[t].size();
        }
        if(tnum != 0){
            h = h / 100 * (100 + r);
            num = tnum;
        }
    }
    printf("%.2lf %d\n", h, num);
	return 0;
}
