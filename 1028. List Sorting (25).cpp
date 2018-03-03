#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Info{
	int ID;
	char name[10];
	int grade;
};

bool cmpID(const Info &a, const Info &b){
	return a.ID < b.ID;
}

bool cmpName(const Info &a, const Info &b){
	int res = strcmp(a.name, b.name);
	if(res == 0){
		return a.ID < b.ID;
	} else if(res < 0){
		return true;
	}
	return false;
}

bool cmpGrade(const Info &a, const Info &b){
	if(a.grade == b.grade){
		return a.ID < b.ID;
	} else if(a.grade < b.grade){
		return true;
	}
	return false;
}

Info info[100000];

int main(){
	int n, c;
	scanf("%d%d", &n, &c);
	for(int i = 0; i < n; i++){
		scanf("%d%s%d", &info[i].ID, info[i].name, &info[i].grade);
	}
	switch(c){
		case 1: sort(info, info + n, cmpID); break;
		case 2: sort(info, info + n, cmpName); break;
		case 3: sort(info, info + n, cmpGrade); break;
	}
	for(int i = 0; i < n; i++){
		printf("%06d %s %d\n", info[i].ID, info[i].name, info[i].grade);
	}
	return 0;
}
