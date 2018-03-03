#include <cstdio>

int main(){
    int asum = 0, bsum = 0, csum = 0, a, b, c;
    for(int i = 0; i < 2; i++){
        scanf("%d.%d.%d", &a, &b, &c);
        asum += a;
        bsum += b;
        csum += c;
    }
    int inc = 0;
    //c
    if(csum >= 29){
        csum -= 29;
        inc = 1;
    }
    //b
    bsum += inc; inc = 0;
    if(bsum >= 17){
        bsum -= 17;
        inc = 1;
    }
    //a
    asum += inc;
    printf("%d.%d.%d\n", asum, bsum, csum);
    return 0;
}
