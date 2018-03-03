#include <cstdio>

int main(){
    int n, m, l, v;
    int dp[205];
    int pos[205];
    scanf("%d", &n);
    for(int i = 1; i <=n; i++){
        dp[i] = 0;
        pos[i] = 0;//喜欢的颜色i在pos[i]位置 不喜欢的在0位置
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%d", &v);
        pos[v] = i;
    }
    scanf("%d", &l);
    int smax;
    for(int i = 0; i < l; i++){
        scanf("%d", &v);
        smax = 0;
        for(int i = 1; i <= pos[v]; i++){
            if(smax < dp[i]) smax = dp[i];
        }
        dp[pos[v]] = smax + 1;
    }
    smax = 0;
    for(int i = 1; i <= m; i++) if(smax < dp[i]) smax = dp[i];
    printf("%d\n", smax);
    return 0;
}
