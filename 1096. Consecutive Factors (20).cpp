#include <cstdio>

typedef long long ll;

int smap[46400][13];

const ll smax = 2147483647;

int main(){
    for(int i = 2; i < 46400; i++){
        long long t = 1;
        for(int j = 1; ; j++){
            smap[i][j] = 0;
            t *= i + j - 1;
            if(t > smax) break;
            else smap[i][j] = t;
        }
    }
    int n, num = 1, st;
    bool flag = false;
    scanf("%d", &n);
    st = n;
    for(int j = 11; j >= 1; j--){
        for(int i = 2; i < 46400; i++){
            if(smap[i][j] == 0 || smap[i][j] > n) break;
            if(n % smap[i][j] == 0){
                num = j;
                st = i;
                flag = true;
                break;
            }
        }
        if(flag)break;
    }
    printf("%d\n", num);
    for(int i = 0; i < num; i++){
        printf("%d%c", st + i, i + 1 == num ? '\n' : '*');
    }
    return 0;
}
