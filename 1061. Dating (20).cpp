/**
    һ�����⣬����Ƚ�����ȫŪ������ر��ǵ�һ���͵ڶ���ֵ��ѡȡ�ж���
    �������£�
    �ڵ�1��2���ַ�����:
    ��λ�Ƚϣ��ҵ���һ����ͬ���ַ�����������[A, G]����Сд���У�
    ��λ�Ƚϣ��ҵ�֮�������[0, 9] ����[A, N]����Сд���У����ַ�
    �ڵ�1��2���ַ�����:
    ��λ�Ƚϣ��ҵ���һ����ͬ����ĸ
*/
#include <cstdio>

bool isTrue(char c, int type){
    switch(type){
        case 1: if(c >= 'A' && c <= 'G') return true;
                break;
        case 2: if((c >= 'A' && c <= 'N') ||
                   (c >= '0' && c <= '9')) return true;
                break;
        case 3: if((c >= 'A' && c <= 'Z') ||
                   (c >= 'a' && c <= 'z')) return true;
                break;
    }
    return false;
}

int main(){
    char str[4][65];
    char s[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int day = -1, hour = -1, minute;
    for(int i = 0; i < 4; i++) scanf("%s", str[i]);
    //type 1 2
    for(int i = 0; ; i++){
        if(str[0][i] == str[1][i]){
            if(day == -1){
                if(isTrue(str[0][i], 1)){
                    day = str[0][i] - 'A';
                }
            } else {
                if(isTrue(str[0][i], 2)){
                    if(str[0][i] >= '0' && str[0][i] <= '9'){
                        hour = str[0][i] - '0';
                    } else {
                        hour = str[0][i] - 'A' + 10;
                    }
                    break;
                }
            }
        }
    }
    //type 3
    for(int i = 0; ; i++){
        if(!isTrue(str[2][i], 3)) continue;
        if(str[2][i] == str[3][i]){
            minute = i;
            break;
        }
    }
    //printf("day: %d\n", day);
    //printf("hour: %d\n", hour);
    //printf("minute: %d\n", minute);
    printf("%s %02d:%02d\n", s[day], hour, minute);
    return 0;
}
/**
1 A
2 B
3 C
4 D
5 E
6 F
7 G
8 H
9 I
10 J
11 K
12 L
13 M
14 N
15 O
16 P
17 Q
18 R
19 S
20 T
21 U
22 V
23 W
24 X
25 Y
26 Z
*/
