#include <cstdio>
typedef long long ll;

struct Num{
    ll a, b;

    Num(ll x){
        a = x;
        b = 1;
    }
    Num(ll a, ll b){
        this->a = a;
        this->b = b;
    }

    Num operator + (Num e){
        return Num(a*e.b+b*e.a, b*e.b);
    }
    Num operator - (Num e){
        return Num(a*e.b-b*e.a, b*e.b);
    }
    Num operator * (Num e){
        return Num(a*e.a, b*e.b);
    }
    Num operator / (Num e){
        return Num(a*e.b, b*e.a);
    }
    void print(){
        if(b == 0){
            printf("Inf");
        } else {
            init();
            ll ta = a;
            if(a < 0){
               printf("(-"); ta = -a;
            } else ta = a;

            if(ta % b == 0)printf("%d", ta / b);
            else {
                if(ta > b) printf("%d %d/%d", ta/b, ta%b, b);
                else printf("%d/%d", ta%b, b);
            }

            if(a < 0){
                printf(")");
            }
        }

    }
    void init(){
        ll t = gcd(this->a, this->b);
        a = a / t;
        b = b / t;
    }
    ll gcd(ll a,ll b){
		if(b == 0) return a;
		return gcd(b,a%b);
	}
};

char op[5] = "+-*/";

int main(){
    int a1, b1, a2, b2;
    scanf("%d/%d %d/%d", &a1, &b1, &a2,&b2);
    Num x(a1, b1), y(a2, b2), z(0);
    for(int i = 0; i < 4; i++){
        switch(i){
            case 0: z = x + y; break;
            case 1: z = x - y; break;
            case 2: z = x * y; break;
            case 3: z = x / y; break;
        }
        x.print();
        printf(" %c ", op[i]);
        y.print();
        printf(" = ");
        z.print();
        printf("\n");
    }
    return 0;
}
