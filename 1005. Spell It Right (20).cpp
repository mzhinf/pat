#include <cstdio>
#include <stack>

using namespace std;

char word[10][6]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
	char str[105];
	scanf("%s", str);
	int sum = 0;
	for(int i = 0; str[i] != '\0'; i++){
		sum += str[i] - '0';
	}
	stack<int> output;
	//注意特殊处理数字0的情况
	if(sum == 0) output.push(0);
	while(sum > 0){
		output.push(sum % 10);
		sum /= 10;
	}
	while(true){
		printf("%s", word[output.top()]);
		output.pop();
		if(output.empty()){
			printf("\n");
			break;
		} else {
			printf(" ");
		}
	}
	return 0;
}
