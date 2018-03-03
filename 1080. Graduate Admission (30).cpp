#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int quota[105];//学校招生人数

struct StuNo{
    int _end;
    vector<int> no;
}school[105];
vector<int>::iterator it;

struct Stu{
    int no;
    int srank;
    int ge;
    int gi;
}stu[40005];
int stuk[40005][5];

bool cmp(const Stu &a, const Stu &b){
    if(a.ge + a.gi > b.ge + b.gi) return true;
    else if(a.ge + a.gi == b.ge + b.gi){
        return a.ge > b.ge;
    } else return false;
}

bool isSame(Stu a, Stu b){
    return (a.ge + a.gi == b.ge + b.gi) && (a.ge == b.ge);
}

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        scanf("%d", &quota[i]);
        school[i]._end = -1;
    }
    for(int i = 0; i < n; i++){
        stu[i].no = i;
        scanf("%d%d", &stu[i].ge, &stu[i].gi);
        for(int j = 0; j < k; j++){
            scanf("%d", &stuk[i][j]);
        }
    }
    //计算rank
    sort(stu, stu + n, cmp);
    int top = 0;
    for(int i = 0; i < n; i++){
        //printf("%d %d %d", stu[i].no, stu[i].ge, stu[i].gi);
        //for(int j = 0; j < k; j++){
        //    printf(" %d", stuk[stu[i].no][j]);
        //}
        //printf("\n");
        if(i == 0 || !isSame(stu[i], stu[i-1])) stu[i].srank = top++;
        else stu[i].srank = top - 1;
    }
    //模拟招生
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            int sno = stuk[stu[i].no][j];
            int srank = stu[i].srank;
            if(quota[sno] > 0 || school[sno]._end == srank){
                quota[sno]--;
                school[sno].no.push_back(stu[i].no);
                school[sno]._end = srank;
                break;
            }
        }
    }
    for(int i = 0; i < m; i++){
        //排序
        sort(school[i].no.begin(), school[i].no.end());
        it = school[i].no.begin();
        if(it != school[i].no.end()){
            printf("%d", *it);
            for(it++; it != school[i].no.end(); it++){
                printf(" %d", *it);
            }
        }
        printf("\n");
    }
    return 0;
}
