#include <cstdio>
#include <cstring>

void inverse(char *str){//µ¹×ª×Ö·û´®
    int len = strlen(str) - 1;
    int half = (len + 1) / 2;
    for(int i = 0; i < half; i++){
        char t = str[i];
        str[i] = str[len - i];
        str[len - i] = t;
    }
}

int main(){
    int n;
    char str[300], s_end[300];
    scanf("%d", &n); getchar();
    for(int i = 0; i < n; i++){
        gets(str);
        inverse(str);
        if(i == 0) strcpy(s_end, str);
        else{
            for(int i = 0; s_end[i] != '\0' && str[i] != '\0'; i++){
                if(s_end[i] != str[i]){
                    s_end[i] = '\0';
                }
            }
        }
    }
    inverse(s_end);
    if(s_end[0] == '\0') strcpy(s_end, "nai");
    printf("%s\n", s_end);
    return 0;
}

/*
//test
gets(str);
printf("%s\n", str);
inverse(str);
printf("%s\n", str);
*/
