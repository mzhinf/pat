#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

stack<int> s;

//尝试使用线段树解决该问题
int n;
int dat[250000];

void init_tree(){
    memset(dat, 0, sizeof(dat));
    n = 1;
    while(n < 100000)n *= 2;
}

void sinsert(int k){
	//叶子节点
	k += n - 1;
	dat[k]++;
	//向上更新
	while(k > 0){
		k = (k - 1) / 2;
		dat[k]++;
	}
}

void sdelete(int k){
	//叶子节点
	k += n - 1;
	dat[k]--;
	//向上更新
	while(k > 0){
		k = (k - 1) / 2;
		dat[k]--;
	}
}

int getMid(){
    int mid = (dat[0] + 1) / 2, ans = 0;
    while(ans < n - 1){
        //ans * 2 + 1
        if(dat[ans * 2 + 1] >= mid){
            ans = ans * 2 + 1;
        } else {
            mid -= dat[ans * 2 + 1];
            ans = ans * 2 + 2;
        }
    }
    return ans - n + 1;
}

void init(){
    //freopen("in.txt", "r", stdin);
    while(!s.empty()) s.pop();
    init_tree();
}

int main(){
    init();
    int t, v;
    char str[10];
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%s", str);
        if(strcmp(str, "Pop") == 0){
            if(s.empty()) printf("Invalid\n");
            else {
                int v = s.top(); s.pop();
                sdelete(v);
                printf("%d\n", v);
            }
        } else if(strcmp(str, "Push") == 0) {
            scanf("%d", &v);
            sinsert(v);
            s.push(v);
        } else if(strcmp(str, "PeekMedian") == 0){
            if(s.empty()) printf("Invalid\n");
            else {
                printf("%d\n", getMid());
            }
        }
    }
    return 0;
}
