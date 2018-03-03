#include <cstdio>

int main(){
    int n;
    int smap[100005], scount[10005];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &smap[i]);
        scount[smap[i]]++;
    }
    int v = -1;
    for(int i = 0; i < n; i++){
        if(scount[smap[i]] == 1){
            v = smap[i];
            break;
        }
    }
    if(v == -1) printf("None\n");
    else printf("%d\n", v);
    return 0;
}
