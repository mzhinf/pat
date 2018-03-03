#include <cstdio>
#include <cstring>

const int mod =1000000007;
char str[100005];
int dp[3];

int main(){
    scanf("%s", str);
    int len = strlen(str);
    //init
    dp[0] = dp[1] = dp[2] = 0;
    for(int i = 1; i <= len; i++){
        switch(str[i-1]){
            case 'P': dp[0] = (dp[0] + 1) % mod; break;
            case 'A': dp[1] = (dp[1] + dp[0]) % mod; break;
            case 'T': dp[2] = (dp[2] + dp[1]) % mod; break;
        }
    }
    printf("%d\n", dp[2]);
    return 0;
}
