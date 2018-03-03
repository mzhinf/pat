#include <cstdio>
#include <algorithm>

using namespace std;

int pos[100005];//pos[i] = j; i pos is j
bool vis[100005];

int main(){
    int n, v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v);
        pos[v] = i;
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        int t = i, t_count = 0;
        while(!vis[t]){
            t_count++;
            vis[t] = true;
            t = pos[t];
        }
        if(i == 0) sum += t_count - 1;
        else if(t_count > 1) sum += t_count + 1;
    }
    printf("%d\n", sum);
    return 0;
}
