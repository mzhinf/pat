/**
    ���⣺
    �Ӹ����������ҳ�������i��j��Ϊsum
    �������ظ�
    ������Ψһʱȡi��С��һ��
    ������� No Solution
    ������
    ʹ��map<value, count>
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
