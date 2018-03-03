#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Person{
    char name[5];
    vector<int> course;
    bool operator < (Person p){
        for(int i = 0; i < 5; i++){
            if(name[i] != p.name[i]) return name[i] < p.name[i];
        }
    }
}person[40005];
vector<int> course[2505];

int main(){
    int n, k, num, v;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%s%d", person[i].name, &num);
        for(int j = 0; j < num; j++){
            scanf("%d", &v);
            person[i].course.push_back(v);
        }
    }
    sort(person, person + n);
    vector<int>::iterator it;
    for(int i = 0; i < n; i++){
        for(it = person[i].course.begin(); it != person[i].course.end(); it++){
            course[*it].push_back(i);
        }
    }
    for(int i = 1; i <= k; i++){
        printf("%d %d\n", i, course[i].size());
        //if(course[i].size() == 0) continue;//course[i].size()为0 自然没有输出
        for(it = course[i].begin(); it != course[i].end(); it++){
            printf("%s\n", person[*it].name);
        }
    }
    return 0;
}
