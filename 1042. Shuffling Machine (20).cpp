#include <cstdio>

void pos_print(int a){
    if(a == 53) printf("J1");
    if(a == 54) printf("J2");
    switch((a - 1) / 13){
        case 0:
            printf("S%d", (a - 1) % 13 + 1);
            break;
        case 1:
            printf("H%d", (a - 1) % 13 + 1);
            break;
        case 2:
            printf("C%d", (a - 1) % 13 + 1);
            break;
        case 3:
            printf("D%d", (a - 1) % 13 + 1);
            break;
    }
}

int main(){
    int n;
    int go[55], pos[2][55];
    int *p = pos[0], *tp = pos[1], *tt;
    scanf("%d", &n);;
    for(int i = 1; i <= 54; i++){
        scanf("%d", &go[i]);
        p[i] = i;
    }
    while(n--){
        tt = p;
        p = tp;
        tp = tt;
        for(int i = 1; i <= 54; i++){
            p[go[i]] = tp[i];
        }
    }
    for(int i = 1; i <= 54; i++){
        pos_print(p[i]);
        if(i == 54) printf("\n");
        else printf(" ");
    }
    return 0;
}
