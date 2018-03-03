#include <cstdio>

int a[1005];
int sstack[1005][2];
int top, sum;

void push(int _top, int _bottom){
    sstack[top][0] = _top;
    sstack[top][1] = _bottom;
    top++;
    sum+= _top - _bottom + 1;
}

int pop(){
    int _top = top - 1, ret = sstack[_top][0];
    if(sstack[_top][0] == sstack[_top][1]){
        top--;
    } else {
        sstack[_top][0]--;
    }
    sum--;
    return ret;
}

int main(){
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    while(k--){
        int number = 1;
        bool flag = true;
        top = sum = 0;
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < n; i++){
            if(sum == 0 || a[i] >= number){
                //push
                push(a[i], number);
                number = a[i] + 1;
                //check
                if(sum > m){
                    flag = false;
                    break;
                }
            }
            if(pop() != a[i]){
                flag = false;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
}