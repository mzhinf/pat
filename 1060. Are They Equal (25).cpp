#include <cstdio>

int work(char *str, char *strd){
    int len = 0, top = 0;
    bool flag = true, point = false;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '.'){
            if(top == 0) len = 0;
            else len = top;
            point = true;
        }
        else if(flag && str[i] == '0'){
            len--;
        }
        else {
            flag = false;
            strd[top++] = str[i];
        }
    }
    if(!point) len = top;
    else if(flag) len = 0;
    strd[top] = '\0';
    return len;
}

int main(){
    int n;
    char a[105], b[105];
    char ad[105], bd[105];
    int ak, bk;
    scanf("%d%s%s", &n, a, b);
    ak = work(a, ad);
    bk = work(b, bd);
    //printf("%d %s\n", ak, ad);
    //printf("%d %s\n", bk, bd);
    bool tequal = true;
    if(ak != bk) tequal = false;
    int ia = 0, ib = 0;
    for(; ad[ia] != '\0'; ia++);
    for(; ia < n; ia++) ad[ia] = '0';
    for(; bd[ib] != '\0'; ib++);
    for(; ib < n; ib++) bd[ib] = '0';
    ad[n] = bd[n] = '\0';
    for(int i = 0 ; i < n; i++){
        if(tequal && ad[i] != bd[i]) tequal = false;
    }
    if(tequal){
        printf("YES 0.%s*10^%d\n", ad, ak);
    } else {
        printf("NO 0.%s*10^%d 0.%s*10^%d\n", ad, ak, bd, bk);
    }
    return 0;
}
