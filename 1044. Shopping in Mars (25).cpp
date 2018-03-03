#include <cstdio>

int a[100005];

int main(){
    int n, m, res, st, ed;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    //find min
    res = 0; st = 1; ed = 0;
    int minM = 10e8 + 10;
    for(int i = 1; i <= n; i++){
        res += a[i];
        ed++;
        while(res >= m){
            if(minM > res) minM = res;
            res -= a[st];
            st++;
        }
    }
    //work
    res = 0; st = 1; ed = 0;
    for(int i = 1; i <= n; i++){
        res += a[i];
        ed++;
        while(res >= m){
            if(minM == res) {
                printf("%d-%d\n", st, ed);
            }
            res -= a[st];
            st++;
        }
    }
    return 0;
}
