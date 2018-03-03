#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <map>

#define MAX_N 205

using namespace std;

char cityName[MAX_N][5];//id -> name
int hap[MAX_N];
int shap[MAX_N];
int step[MAX_N];
int path[MAX_N];
map<string, int> nameToid;//name -> id
int cost[MAX_N][MAX_N];
int pre[MAX_N];
int used[MAX_N];
int d[MAX_N];
int n;//数量
stack<int> output;

void dij(int st, int ed){
    for(int i = 0; i < n; i++) pre[i] = -1;
    memset(used, 0, sizeof(used));
    memset(d, 0x3f, sizeof(d));
    memset(shap, 0, sizeof(shap));
    memset(step, 0x3f, sizeof(step));
    memset(path, 0, sizeof(path));
    d[st] = 0;
    step[st] = 0;
    path[st] = 1;
    while(true){
        int v = -1;
        //取最小
        for(int i = 0; i < n; i++){
            if(!used[i] && (v == -1 || d[i] < d[v])) v = i;
        }
        if(v == -1 || v == ed)break;
        used[v] = true;
        //扩展
        for(int i = 0; i < n; i++){
            if(cost[v][i] == 0x3f3f3f3f)continue;
            if(d[v] + cost[v][i] < d[i]){//比较花费
                d[i] = d[v] + cost[v][i];
                shap[i] = shap[v] + hap[i];
                pre[i] = v;
                step[i] = step[v] + 1;
                path[i] = path[v];
            } else if (d[v] + cost[v][i] == d[i]) {
                path[i] += path[v];
                if(shap[i] < shap[v] + hap[i]){//比较happy
                    shap[i] = shap[v] + hap[i];
                    pre[i] = v;
                    step[i] = step[v] + 1;
                } else if(shap[i] == shap[v] + hap[i]){
                    if(step[i] > step[v] + 1){//比较城市数目即平均
                        shap[i] = shap[v] + hap[i];
                        pre[i] = v;
                        step[i] = step[v] + 1;
                    }
                }
            }
        }
    }
}

int main(){
    memset(cost, 0x3f, sizeof(cost));
    int k, st = 0, ed, h, a, b, c;
    char sa[5], sb[5];
    scanf("%d%d%s", &n, &k, cityName[0]);
    hap[0] = 0;
    for(int i = 1; i < n; i++){//id [0,n)
        scanf("%s%d", cityName[i], &h);
        nameToid.insert(make_pair(cityName[i], i));
        hap[i] = h;
        if(strcmp("ROM", cityName[i]) == 0) ed = i;
    }
    for(int i = 0; i < k; i++){
        scanf("%s%s%d", sa, sb, &c);
        a = nameToid.find(sa)->second;
        b = nameToid.find(sb)->second;
        cost[a][b] = c;
        cost[b][a] = c;
    }
    dij(st, ed);
    //层次遍历
    for(int i = ed; i != -1; i = pre[i]){
        output.push(i);
    }
    printf("%d %d %d %d\n", path[ed], d[ed], shap[ed], shap[ed]/step[ed]);
    while(true){
        int t = output.top(); output.pop();
        if(output.empty()){
            printf("%s\n", cityName[t]);
            break;
        }
        else printf("%s->", cityName[t]);
    }
    return 0;
}
/*
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
3 3 195 97
HZH->PRS->ROM
*/
