#include <cstdio>
#include <set>
#include <string>

using namespace std;

int main(){
	int m, n, s;
	char str[25];
	set<string> winners;
	scanf("%d%d%d", &m, &n, &s);
	int k = n;
	for(int i = 1; i <= m; i++){
		scanf("%s", str);
		if(i < s) continue;
		if(k == n){
			if(winners.find(str) == winners.end()){
				printf("%s\n", str);
				winners.insert(str);
				k = 1;
			}
		} else k++;
	}
	if(winners.size() == 0){
		printf("Keep going...\n");
	}
	return 0;
}
