#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> cToStu[2505];//course student list
vector<int>::iterator vit;
vector<int> stuToc[26*26*26*10+5];//student course list
vector<int>::iterator clist;
char students[40005][5];

int NameToId(char *str){
    int res = (str[0] - 'A') * 26 * 26 * 10+
            (str[1] - 'A') * 26 * 10+
            (str[2] - 'A') * 10 +
            (str[3] - '0');
    return res;
}

int main(){
    int stuNum, cNum, v, num;
    char str[5];
    scanf("%d%d", &stuNum, &cNum);
    //init course
    for(int i = 0; i < cNum; i++){
        scanf("%d%d", &v, &num);
        while(num--){
            scanf("%s", str);
            int id = NameToId(str);
            cToStu[v].push_back(id);
        }
    }
    //init student
    for(int i = 0; i < stuNum; i++){
        scanf("%s", students[i]);
    }
    //main
    for(int k = 1; k <= cNum; k++){
        for(vit = cToStu[k].begin(); vit != cToStu[k].end(); vit++){
            stuToc[*vit].push_back(k);
        }
    }
    //output
    for(int i = 0; i < stuNum; i++){
        int k = NameToId(students[i]);
        printf("%s %d", students[i], stuToc[k].size());
        for(clist = stuToc[k].begin(); clist != stuToc[k].end(); clist++){
            printf(" %d", *clist);
        }
        printf("\n");
    }
    return 0;
}

/**
//最后一个 case 运行超时
#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, int> nameToId;//student name to id
map<string, int>::iterator mit;
vector<string> cToStu[2505];//course student list
vector<string>::iterator vit;
vector<int> stuToc[40005];//student course list
vector<int>::iterator clist;
char course[2505][5];

int main(){
    int stuNum, cNum, v, num;
    char str[5];
    scanf("%d%d", &stuNum, &cNum);
    //init course
    for(int i = 0; i < cNum; i++){
        scanf("%d%d", &v, &num);
        while(num--){
            scanf("%s", str);
            cToStu[v].push_back(str);
        }
    }
    //init student 段错误
    for(int i = 0; i < stuNum; i++){
        scanf("%s", course[i]);
        nameToId.insert(make_pair(course[i], i));
    }
    //main
    for(int k = 1; k <= cNum; k++){
        for(vit = cToStu[k].begin(); vit != cToStu[k].end(); vit++){
            stuToc[nameToId.find(*vit)->second].push_back(k);
        }
    }
    //output
    for(int i = 0; i < stuNum; i++){
        printf("%s %d", course[i], stuToc[i].size());
        for(clist = stuToc[i].begin(); clist != stuToc[i].end(); clist++){
            printf(" %d", *clist);
        }
        printf("\n");
    }
    return 0;
}
*/
