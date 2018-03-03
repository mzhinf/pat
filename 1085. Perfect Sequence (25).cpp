#include <cstdio>
#include <algorithm>

using namespace std;

long long a[100005];

int main(){
    int n, p;
    scanf("%d%d", &n, &p);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    int smax = 0, t = 0, m = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > a[m] * p){
            if(smax < t) smax = t;
            while(a[i] > a[m] * p){
                m++;
                t--;
            }
        }
        t++;
    }
    if(smax < t) smax = t;
    printf("%d\n", smax);
    return 0;
}
/*
3 8
1 9 10

4 8
1 9 10 73
*/
