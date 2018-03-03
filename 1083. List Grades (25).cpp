#include <cstdio>
#include <algorithm>

using namespace std;

struct Person{
    char name[12];
    char id[12];
    int grade;
}stu[105];

bool cmp(const Person &a, const Person &b){
    return a.grade > b.grade;
}

int main(){
    int n, left, right;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s%s%d", stu[i].name, stu[i].id, &stu[i].grade);
    }
    sort(stu, stu + n, cmp);
    scanf("%d%d", &left, &right);
    bool flag = true;
    for(int i = 0; i < n; i++){
        if(stu[i].grade >= left && stu[i].grade <= right){
            printf("%s %s\n", stu[i].name, stu[i].id);
            flag = false;
        }
    }
    if(flag){
        printf("NONE\n");
    }
    return 0;
}
