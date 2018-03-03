#include <cstdio>
#include <queue>
#include <stack>
#include <string>

using namespace std;

char number[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

queue<int> num;
stack<string> output;
void workOutput(){
    bool flag = false;
    for(int i = 0; !num.empty() && i < 4; i++){
        int v = num.front(); num.pop();
        if(v != 0){
            switch(i){
                case 1: output.push("Shi"); break;
                case 2: output.push("Bai"); break;
                case 3: output.push("Qian"); break;
            }
            output.push(number[v]);
            flag = true;
        } else {
            //判断是否可以加0
            if(flag){
                output.push("ling");
                flag = false;
            }
        }
    }
}


int main(){
	int n;
	scanf("%d", &n);
	bool fu = false;
	if(n < 0){
        fu = true;
        n = -n;
	} else if(n == 0) {
        output.push("ling");//特殊处理0
	}
    while(n > 0){
        num.push(n % 10);
        n /= 10;
    }
    //1-4
    workOutput();
    //5-8 万
    output.push("Wan");
    int st = output.size();
    workOutput();
    if(st == output.size()){
        output.pop();//长度没变化 说明全0 删去"Wan"
    }
    //9
    if(!num.empty()){
        int v = num.front(); num.pop();
        output.push("Yi");
        output.push(number[v]);
    }
    if(fu){
       printf("Fu ");
    }
    while(!output.empty()){
        printf("%s", output.top().c_str());
        output.pop();
        printf("%c", output.empty() ? '\n' : ' ');
    }
	return 0;
}
