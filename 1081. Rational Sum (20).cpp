#include <cstdio>

typedef long long ll;

struct F{
    ll x;
    ll y;
    F(ll x){
        this->x = x;
        y = 1;
    }
    F(ll x, ll y){
        ll t = gcd(x > 0 ? x : -x, y);
        this->x = x / t;
        this->y = y / t;
    }
    F operator + (F f){
        return F(x * f.y + f.x * y, y * f.y);
    }
    ll gcd(ll a, ll b){
        return a%b == 0 ? b : gcd(b, a%b);
    }
};


int main(){
    int n, a, b;
    F f(0);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d/%d", &a, &b);
        F tf(a, b);
        f = f + tf;
        //printf("%lld/%lld\n", f.x, f.y);
    }
    a = f.x > 0 ? f.x : -f.x;
    b = f.y;
    int q = a/b, w = a%b, e = b;
    if(f.x < 0){
        q = -q;
        w = -w;
    }
    if(q != 0 && w != 0){
        printf("%d %d/%d", q, w, e);
    } else if(w != 0){
        printf("%d/%d", w, e);
    } else if(q != 0){
        printf("%d", q);
    } else {
        printf("0");
    }
    return 0;
}

/*
5
-2/5 -4/15 -1/30 2/60 -8/3

*/
