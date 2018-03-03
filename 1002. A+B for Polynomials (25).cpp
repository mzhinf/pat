#include <cstdio>

int main(){
	int n, num = 2, pos;
	double a[1005] = {0}, v;
	while(num--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d%lf", &pos, &v);
			a[pos] += v;
		}
	}
	int sum = 0;
	for(int i = 0; i <= 1000; i++){
		if(a[i] != 0)sum++;
	}
	printf("%d", sum);
	for(int i = 1000; i >= 0; i--){
		if(a[i] != 0) printf(" %d %.1lf", i, a[i]);
	}
	return 0;
}
