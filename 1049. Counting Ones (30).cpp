#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	long long n, tn, i = 10, j = 1, sum = 0;
	scanf("%lld", &n);
	tn = n + 1;
    while(n > 0){
        //(n+1)/10^i * 10^(i-1) -> tn/i*j
        //min(10^(i-1), (n+1)%10^i-10^(i-1)[小于0取0]) -> min()
        sum += tn/i*j + ((tn%i - j) > 0 ? min(j, tn%i - j) : 0);
        i *= 10;
        j *= 10;
        n /= 10;
    }
    printf("%lld\n", sum);
	return 0;
}
