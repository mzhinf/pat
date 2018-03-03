#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Info{
	long long no;
	int local_no;
	int grade;
};

bool cmp(const Info &a, const Info &b){
	return a.grade == b.grade ? a.no < b.no : a.grade > b.grade;
}

int main(){
	int n, k, num = 0;
	vector<Info> infos;
	vector<int> rank, record, jump;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &k);
		num += k;
		for (int j = 0; j < k; ++j){
			Info info;
			scanf("%lld%d", &info.no, &info.grade);
			info.local_no = i;
			infos.push_back(info);
		}
	}
	for (int i = 0; i <= num; ++i){
		rank.push_back(0);
		record.push_back(-1);
		jump.push_back(1);
	}
	sort(infos.begin(), infos.end(), cmp);
	printf("%d\n", num);
	for (int i = 0; i < num; ++i){
		if(record[0] != infos[i].grade){
			record[0] = infos[i].grade;
	        rank[0] += jump[0];
	        jump[0] = 1;
		} else {
			jump[0]++;
		}
		if(record[infos[i].local_no] != infos[i].grade){
			record[infos[i].local_no] = infos[i].grade;
	        rank[infos[i].local_no] += jump[infos[i].local_no];
	        jump[infos[i].local_no] = 1;
		} else {
			jump[infos[i].local_no]++;
		}
		printf("%013lld %d %d %d\n", infos[i].no, rank[0], infos[i].local_no, rank[infos[i].local_no]);
	}
	return 0;
}