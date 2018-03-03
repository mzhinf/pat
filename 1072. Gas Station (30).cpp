#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
int N, M, K, D;
int cost[1015][1015];//houses:1 - 1000 Gas Station:N + 1 - N + 10
int d[1015];
bool vis[1015];

struct Gas{
    int id;
    double average;
    double min;
}gas[15];

bool cmp(const Gas &a, const Gas &b){
    if(a.min > b .min){
        return true;
    } else if(a.min == b.min){
        if(a.average < b.average){
            return true;
        } else if(a.average == b.average){
            return a.id < b.id;
        }
    }
    return false;
}

void init(){
    for(int i = 1; i <= N + M; i++){
        d[i] = inf;
        vis[i] = false;
    }
}

void dij(int st){
    init();
    d[N + st] = 0;
    while(true){
        int v = -1;
        //choice min
        for(int i = 1; i <= N + M; i++){
            if(!vis[i] && d[i] < D//d[i] >= D 说明无法再继续扩展
               && (v == -1 || d[i] < d[v])){
                v = i;
            }
        }
        if(v == -1) break;
        vis[v] = true;
        //extend
        for(int i = 1; i <= N + M; i++){
            if(cost[v][i] == inf) continue;
            else {
                if(d[i] > d[v] + cost[v][i]){
                    d[i] = d[v] + cost[v][i];
                }
            }
        }
    }
    int j;
    double sum = 0, ssmin = inf;
    for(j = 1; j <= N; j++){
        if(d[j] <= D){
            sum += d[j];
            if(ssmin > d[j]) ssmin = d[j];
        } else break;
    }
    gas[st].id = st;
    if(j == N + 1){
        gas[st].average = sum / N;
        gas[st].min = ssmin;
    } else gas[st].min = -1;
}

int judge(char *str){
    int res = 0, s_add = 0;
    if(str[0] == 'G'){
        s_add = N;
        str++;
    }
    for(int i = 0; str[i] != '\0'; i++){
        res = res * 10 + str[i] - '0';
    }
    return res + s_add;
}

int main(){
    char str_a[5], str_b[5];
    int a, b, v;
    memset(cost, 0x3f, sizeof(cost));
    scanf("%d%d%d%d", &N, &M, &K, &D);
    for(int i = 0; i < K; i++){
        scanf("%s%s%d", str_a, str_b, &v);
        a = judge(str_a);
        b = judge(str_b);
        cost[a][b] = v;
        cost[b][a] = v;
    }
    for(int i = 1; i <= M; i++){
        dij(i);
    }
    sort(gas + 1, gas + M + 1, cmp);
    if(gas[1].min != -1){
        printf("G%d\n%.1lf %.1lf\n", gas[1].id, gas[1].min, gas[1].average);
    } else {
        printf("No Solution\n");
    }
    return 0;
}
