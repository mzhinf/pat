#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Person{
    char name[9];
    int age;
    int worth;
}person[100005];

bool cmp(const Person &a, const Person &b){
    if(a.worth > b.worth){
        return true;
    } else if(a.worth == b.worth){
        if(a.age < b.age){
            return true;
        } else if(a.age == b.age){
            return strcmp(a.name, b.name) < 0;
        }
    }
    return false;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%s%d%d", person[i].name, &person[i].age, &person[i].worth);
    }
    sort(person, person + n, cmp);
    for(int i = 1; i <= k; i++){
        int num, left, right, temp = 0;
        scanf("%d%d%d", &num, &left, &right);
        printf("Case #%d:\n", i);
        for(int j = 0; j < n; j++){
            if(person[j].age >= left && person[j].age <= right){
                printf("%s %d %d\n", person[j].name, person[j].age, person[j].worth);
                temp++;
            }
            if(num == temp) break;
        }
        if(temp == 0) printf("None\n");
    }
    return 0;
}
