#include <cstdio>
//素数测试 O(√n)
bool is_prime(int n){
	if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
//十进制数num按照radix进制倒转
int reversible(int num, int radix){
    int res = 0;
	while(num > 0){
        res = res * radix + num % radix;
		num /= radix;
	}
	return res;
}

int main(){
	int num, radix;
	while(~scanf("%d", &num) && num > 0){
		scanf("%d", &radix);
		int t = reversible(num, radix);
		printf("%s", is_prime(num) && is_prime(t) ? "Yes\n" : "No\n");
	}
	return 0;
}
