#include <cstdio>
int num, smax, smin, temp = -1;
void work(){
    int a[10] = {0}, t, zero = 4;
    t = num;
    zero = 4;
    while(t > 0){
        a[t % 10]++;
        t /= 10;
        zero--;
    }
    a[0] += zero;
    smax = 0, smin = 0;
    for(int i = 9; i >= 0; i--){
        for(int j = 0; j < a[i]; j++){
            smax = smax * 10 + i;
        }
    }
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j < a[i]; j++){
            smin = smin * 10 + i;
        }
    }
}

int main(){
    bool flag = false;
    scanf("%d", &num);
    while(true){
        work();
        temp = smax - smin;
        if(temp == num && flag) break;
        printf("%04d - %04d = %04d\n", smax, smin, temp);
        num = temp;
        flag = true;
    }
    return 0;
}
/**
in:
6174
out:
7641 - 1467 = 6174
*/
