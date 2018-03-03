/**
    i - j
    1.i-j
    d[j] - d[i];
    2.j-n-1-i
    d[n]-d[j] + d[n->1] + d[i] - d[1]
    or d[cycle] - (d[j] - d[i])
*/
#include <cstdio>
int d[100005];

void sswap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

int main(){
    int n, m, v, st, ed;
    scanf("%d", &n);
    d[1] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &v);
        d[i + 1] = d[i] + v;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &st, &ed);
        if(st > ed) sswap(st, ed);
        int ta = d[ed] - d[st];
        int tb = d[n + 1] - ta;
        printf("%d\n", ta < tb ? ta : tb);
    }
    return 0;
}
