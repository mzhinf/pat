#include <cstdio>

//[0-9], [a-z], [A-Z] 10+26+26
int num[2][65];
char str[2][1005];

int return_num(char a){
    int v = 0;
    if(a <= '9' && a >='0') v = a - '0';
    else if(a <= 'z' && a >= 'a') v = a - 'a' + 10;
    else v = a - 'A' + 36;
    return v;
}

int main(){
    scanf("%s%s", str[0], str[1]);
    for(int i = 0; i < 2; i++){
        for(int j = 0; str[i][j] != '\0'; j++){
            num[i][return_num(str[i][j])]++;
        }
    }
    int miss = 0, surplus = 0;
    for(int i = 0; i < 62; i++){
        int v = num[0][i] - num[1][i];
        if(v < 0){//ȱ
            miss += -v;
        } else {
            surplus += v;
        }
    }
    if(miss == 0) printf("Yes %d\n", surplus);
    else printf("No %d", miss);
    return 0;
}
