/*
    make_pair<int, int> 在PAT上报错
*/
#include <cstdio>
//Boyer-Moore Algorithm 方法1
int main(){
	int n, m, v;
	scanf("%d%d",&n,&m);
	int candidate = 0, count = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &v);
			if(count == 0){
				candidate = v;
			}
			if(candidate == v){
				count += 1;
			} else {
				count -= 1;
			}
		}
	}
	printf("%d\n", candidate);
	return 0;
}

/*
#include <cstdio>
#include <map>
using namespace std;
//统计方法 方法2
int main(){
	int n, m, v;
	map<int, int> smap;
	map<int,int>::iterator sit;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &v);
			sit = smap.find(v);
			if(sit != smap.end()){
				sit -> second = sit -> second + 1;
			} else {
				smap.insert(make_pair(v, 1));
			}
		}
	}
	int smax = -1, ssum = -1;
	for(sit = smap.begin(); sit != smap.end(); sit++){
		if(ssum < sit->second){
			ssum = sit->second;
			smax = sit->first;
		}
	}
	printf("%d\n", smax);
	return 0;
}
*/
