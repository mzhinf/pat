/**
	根据条件判断4类人，排序输出
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Person{
    int id;
    int virtue;
    int talent;
    int sum;
    Person(int id, int virtue, int talent){
        this->id = id;
        this->virtue = virtue;
        this->talent = talent;
        this->sum = virtue + talent;
    }
};

bool cmp(const Person &a, const Person &b){
    if(a.sum > b.sum){
        return true;
    } else if (a.sum == b.sum){
        if(a.virtue > b.virtue){
            return true;
        } else if (a.virtue == b.virtue){
            return a.id < b.id;
        }
    }
    return false;
}

vector<Person> person[4];
vector<Person>::iterator it;

int main(){
    int N, L, H, n = 0;
    scanf("%d%d%d", &N, &L, &H);
    for(int i = 0; i < N; i++){
        int id, virtue, talent;
        scanf("%d%d%d", &id, &virtue, &talent);
        Person temp(id, virtue, talent);
        if(virtue < L || talent < L) continue;
        n++;
        if(virtue >= H && talent >= H){//sage
            person[0].push_back(temp);
        } else if (virtue >= H) {//nobleman
            person[1].push_back(temp);
        } else if (talent < H && virtue >= talent) {//fool man
            person[2].push_back(temp);
        } else person[3].push_back(temp);//small man
    }
    printf("%d\n", n);
    for(int i = 0; i < 4; i++){
        sort(person[i].begin(), person[i].end(), cmp);
        for(it = person[i].begin(); it != person[i].end(); it++){
            printf("%d %d %d\n", (*it).id, (*it).virtue, (*it).talent);
        }
    }
    return 0;
}
