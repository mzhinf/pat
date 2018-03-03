#include <cstdio>
#include <algorithm>

using namespace std;

struct Mooncake {
    double amount;
    double price;
    double single;
}cake[1005];

bool cmp(const Mooncake &a, const Mooncake &b){
    return a.single > b.single;
}

int main(){
    int n;
    double sum;
    scanf("%d%lf", &n, &sum);
    for(int i = 0; i < n; i++){
        scanf("%lf", &cake[i].amount);
    }
    for(int i = 0; i < n; i++){
        scanf("%lf", &cake[i].price);
        cake[i].single = cake[i].price / cake[i].amount;
    }
    sort(cake, cake + n, cmp);
    double profit = 0;
    for(int i = 0; sum > 0 && i < n; i++){
        if(sum >= cake[i].amount){
            profit += cake[i].price;
            sum -= cake[i].amount;
        } else {
            profit += sum * cake[i].single;
            break;
        }
    }
    printf("%.2lf\n", profit);
    return 0;
}
