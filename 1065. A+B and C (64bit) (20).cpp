#include <cstdio>

int main(){
    long long a, b, c;
    int t;
    bool flag;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("Case #%d: ", i);
        if(a > 0 && b > 0){//a>0 b>0
            if(c <= 0){//c<=0
                flag = true;
            } else {//c>0
                if(a > c - b) flag =true;
                else flag = false;
            }
        }
        else if(a < 0 && b < 0){//a<0 b<0
            if(c >= 0){//c>=0
                flag = false;
            } else {//c<0
                if(a > c - b) flag =true;
                else flag = false;
            }
        } else {
            if(a + b > c) flag =true;
            else flag = false;
        }
        if(flag) printf("true\n");
        else printf("false\n");
    }
    return 0;
}
