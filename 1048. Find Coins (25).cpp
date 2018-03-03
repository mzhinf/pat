/**
    题意：
    从给定序列中找出两个数i，j和为sum
    序列有重复
    两数不唯一时取i最小的一组
    否则输出 No Solution
    分析：
    使用map<value, count>
*/
#include <cstdio>
#include <map>

using namespace std;

int main(){
    int n, sum, half, v;
    map<int, int> smap;
    map<int, int>::iterator mit, t;
    scanf("%d%d", &n, &sum);
    half = sum / 2;
    for(int i = 0; i < n; i++){
        scanf("%d", &v);
        smap[v]++;
    }
    for(mit = smap.begin(); ; mit++){
        if(mit == smap.end() || mit->first > half){
            printf("No Solution\n");
            break;
        }
        t = smap.find(sum - mit->first);
        if(t != smap.end()){
            if((t == mit && t->second >=2) || t != mit){
                printf("%d %d\n", mit->first, t->first);
                break;
            }
        }
    }
    return 0;
}
