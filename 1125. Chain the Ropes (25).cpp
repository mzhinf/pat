#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

struct cmp{
    bool operator () (double & a,double & b){
        return a > b;
    }
};

int main(){
	priority_queue<double, vector<double>, cmp> pq;
	int n;
	double v;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lf", &v);
		pq.push(v);
	}
	while(pq.size() != 1){
		double a = pq.top(); pq.pop();
		double b = pq.top(); pq.pop();
		//printf("%lf %lf\n", a, b);
		pq.push((a + b) / 2);
	}
	printf("%.0lf\n", floor(pq.top()));
	return 0;
}
