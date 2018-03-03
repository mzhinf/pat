#include <cstdio>
#include <cstring>

/*
	1/l
	1 -> @	l -> L
	0/O
	0 -> %	O -> o

*/


int sp;
char existStr[1005][2][11];

void init(){
	sp = 0;
	memset(existStr, 0, sizeof(existStr));
}

bool judge(char *str){
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i]=='1'
		||str[i]=='l'
		||str[i]=='0'
		||str[i]=='O')return true;
	}
	return false;
}

void strchange(char *str){
	for(int i = 0; str[i] != '\0'; i++){
		switch(str[i]){
			case '1': str[i]='@'; break;
			case 'l': str[i]='L'; break;
			case '0': str[i]='%'; break;
			case 'O': str[i]='o'; break;
		}
	}
}

int main(){
	int n;
	char str[2][11];
	scanf("%d", &n);
	init();
	for(int i = 0; i < n; i++){
		scanf("%s%s", str[0], str[1]);
		if(judge(str[1])){
            strchange(str[1]);
			strcpy(existStr[sp][0], str[0]);
			strcpy(existStr[sp][1], str[1]);
			sp++;
		}
	}
	if(sp != 0){
		printf("%d\n", sp);
		for(int i = 0; i < sp; i++){
            printf("%s %s\n", existStr[i][0], existStr[i][1]);
		}
	} else {
		if(n == 1) printf("There is 1 account and no account is modified\n");
		else printf("There are %d accounts and no account is modified\n", n);
	}
	return 0;
}
