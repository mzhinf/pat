#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

struct M{
    int size;
    int finally;
};

int coins[10005];
M dp[105];
stack<int> out;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &coins[i]);
    }
    sort(coins, coins + n);
    //背包
    dp[0].size = 0;
    dp[0].finally = 0;
    for(int i = 0; i < n; i++){//coins[i]
        for(int k = m; k >= 0; k--){//k 从 m-0 不会产生后效性
            if(k == 0 || dp[k].size != 0){
                int temp = k + coins[i];
                if(temp <= m){
                    if(dp[temp].size <= dp[k].size + 1){
                        dp[temp].size = dp[k].size + 1;
                        dp[temp].finally = coins[i];
                    }//else if 两个size相同时 取finally最大的
                    //因为数据已经排序所以后面的数据可以直接覆盖前面的数据
                }
            }
        }
    }
    if(dp[m].size == 0){
        printf("No Solution\n");
    } else {
        for(int t = m; t > 0; t -= dp[t].finally){
            out.push(dp[t].finally);
        }
        for(int i = 0; i < dp[m].size; i++){
            int t = out.top(); out.pop();
            printf("%d%c", t, i + 1 == dp[m].size ? '\n' : ' ');
        }
    }
    return 0;
}
