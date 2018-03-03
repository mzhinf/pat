/**
    ע�⣺1 = 1
*/
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    printf("%d=", n);
    if(n == 1){
        printf("1\n");
    } else {
        int len = sqrt(n);
        vector<int> out[2];
        for(int i = 2; i <= len; i++){
            int j = 0;
            while(n % i == 0){
                n /= i;
                j++;
            }
            if(j != 0){
                out[0].push_back(i);
                out[1].push_back(j);
            }
        }
        if(n != 1){
            out[0].push_back(n);
            out[1].push_back(1);
        }
        len = out[0].size();
        for(int i = 0; i < len; i++){
            printf("%d", out[0][i]);
            if(out[1][i] != 1){
                printf("^%d", out[1][i]);
            }
            if(i + 1 != len) printf("*");
            else printf("\n");
        }
    }
    return 0;
}
