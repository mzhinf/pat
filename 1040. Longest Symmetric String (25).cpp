/**
	Manacher算法模板
*/
#include <cstdio>
#include <algorithm>

using namespace std;
//----- Manacher start -----
#define MAX_NUM 1000 //string max len
int Manacher(char *s){
	int MaxRight = 0, pos = 0, MaxLen = 0, len;
	char str[MAX_NUM * 2 + 5];
	int RL[MAX_NUM * 2 + 5] = {0};
	//str init
	for(int i = 0; ; i++){
		str[i * 2] = '#';
		str[i * 2 + 1] = s[i];
		if(s[i] == '\0'){
            len = 2 * i + 1;
            break;
		}
	}
	//printf("%s\n", str);
    for(int i = 0; i < len; i++){
        if (i < MaxRight) RL[i] = min(RL[2 * pos - i], MaxRight - i);
        else RL[i] = 1;
        //尝试扩展, 注意处理边界
        while (i - RL[i] >= 0 &&
               i + RL[i] < len &&
               str[i - RL[i]] == str[i + RL[i]]) RL[i]++;
        //更新MaxRight, pos
        if (RL[i] + i - 1 > MaxRight){
            MaxRight = RL[i] + i - 1;
            pos = i;
        }
        //更新最长回文串的长度
        MaxLen = max(MaxLen, RL[i]);
    }
    //printf("%d\n", MaxLen - 1);
    return MaxLen - 1;
}
//----- Manacher end -----

int main(){
	char str[1005];
	gets(str);
	printf("%d\n", Manacher(str));
	return 0;
}
