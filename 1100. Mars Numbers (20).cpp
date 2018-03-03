#include <cstdio>
#include <cstring>

char base[13][5]={"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char high[13][5]={"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

char str[10];

void work(){
    if(str[0]>='0' && str[0]<='9'){
        //str -> int
        int res = 0;
        for(int i = 0; str[i] != '\0' ; i++){
            res = res * 10 + str[i] - '0';
        }
        //int -> Mars int
        int h = res/13, b = res%13;
        //Mars int -> output
        if(h == 0){
            printf("%s\n", base[b]);
        } else if(b == 0){
            printf("%s\n", high[h]);
        } else {
            printf("%s %s\n", high[h], base[b]);
        }
    } else {
        char s[2][5];
        int num = 0, len = 0;
        for(int i = 0;;i++){
            if(str[i]=='\0'){
                s[num][len] = '\0';
                break;
            } else if(str[i] == ' ') {
                s[num][len] = '\0';
                len = 0;
                num++;
            } else {
                s[num][len++] = str[i];
            }
        }
        int h = 0, b = 0;
        for(int i = 1; i < 13; i++){
            if(strcmp(high[i], s[0])==0)h = i;
            if(strcmp(base[i], s[0])==0)b = i;
            if(num == 1 && strcmp(base[i], s[1])==0)b = i;
        }
        printf("%d\n", h * 13 + b);
    }
}

int main(){
	int n;
	scanf("%d", &n);getchar();
	while(n--){
		scanf("%[^\n]", str);getchar();
		work();
	}
	return 0;
}
