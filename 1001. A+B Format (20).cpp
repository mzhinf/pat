/*
    注:
    1.处理分割数前导0的情况 -> 100,000
    2.处理特殊情况 0 -> 0
*/
#include <cstdio>
#include <stack>

using namespace std;

void format(int v){
	stack<int> s;
	if(v < 0){
		printf("-");
		v = -v;
	} else if (v == 0){
        printf("0\n");
        return ;
	}
	//将每位数压入栈 压入3的倍数 不够用前导0补齐
	for(int i = 0; v > 0 || i % 3 != 0; i++){
		s.push(v % 10);
		v /= 10;
	}
	bool flag = true;
	while(!s.empty()){
		int out = 0;
		for(int i = 0; i < 3 && !s.empty(); i++){
			out = out * 10 + s.top(); s.pop();
		}
		if(flag) printf("%d", out);//特殊处理第一个数的前导0
		else printf("%03d", out);
		printf("%c", s.empty() ? '\n' : ',');
		flag = false;
	}
}

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	format(a + b);
	return 0;
}
