/*
    str[0] '+' or '-'
    str[2] '.'
    str[i] == 'E'
    str[i + 1] '+' or '-'
    1, 3 - i-1 -> a
    i+2 - end -> e
    a * 10^e
*/
#include <cstdio>

int main(){
    char str[10005], a[10005];
    scanf("%s", str);
    //a
    a[0] = str[1];
    int i = 1, j;
    while(true){
        if(str[i + 2] == 'E'){
            a[i] = '\0';
            i+=3;
            break;
        }
        a[i] = str[i + 2];
        i++;
    }
    //printf("%s %d\n", a, i);
    //e
    int e = 0;
    for(j = i + 1; str[j] != '\0'; j++){
        e = e * 10 + str[j] - '0';
    }
    //printf("%d\n", e);
    if(str[0] == '-'){
        printf("-");
    }
    if(str[i] == '-'){
        printf("0.");
        for(j = 1; j < e; j++) printf("0");
        printf("%s\n", a);
    } else {
        int tl = 0;
        for(j = 0; a[j - tl] != '\0' ; j++){
            if(j == 1 + e) {
                printf(".");
                tl = 1;
            } else {
                printf("%c", a[j - tl]);
            }
        }
        for(; j < e + 1; j++) printf("0");
    }
    return 0;
}
