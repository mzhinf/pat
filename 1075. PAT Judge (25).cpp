#include <cstdio>
#include <algorithm>

using namespace std;

int k;
int full_mark[5];

struct StuInf{
    int id;
    int score[6];
    int ssum;
    int full_mark;
    int srank;
    bool output;
}student[10005];

bool cmp(const StuInf &a, const StuInf &b){
    if(a.ssum > b.ssum){
        return true;
    } else if (a.ssum == b.ssum){
        if(a.full_mark > b.full_mark){
            return true;
        } else if (a.full_mark == b.full_mark){
            return a.id < b.id;
        }
    }
    return false;
}

void init(int n){
    for(int i = 1; i <= n; i++){
        student[i].id = i;
        student[i].full_mark = 0;
        student[i].ssum = 0;
        student[i].output = false;
        for(int j = 0; j < k; j++)student[i].score[j] = -1;
    }
}


int main(){
    int n, m, no, tk, score;
    scanf("%d%d%d", &n, &k, &m);
    init(n);
    for(int i = 0; i < k; i++)scanf("%d", &full_mark[i]);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &no, &tk, &score);
        if(score != -1){
            student[no].output = true;
        } else score = 0;
        if (student[no].score[tk - 1] < score){
            student[no].score[tk - 1] = score;
            if(score == full_mark[tk - 1])student[no].full_mark++;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j++){
             if(student[i].score[j] == -1)continue;
             student[i].ssum += student[i].score[j];
        }
    }
    sort(student + 1, student + n + 1, cmp);
    int srank = 1, same = 1;
    student[1].srank = 1;
    for(int i = 2; i <= n; i++){
        if(student[i].ssum == student[i - 1].ssum){
            student[i].srank = srank;
            same++;
        } else {
            student[i].srank = srank + same;
            srank += same;
            same = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        if(student[i].ssum == 0 && !student[i].output)continue;
        printf("%d %05d %d", student[i].srank,
                             student[i].id,
                             student[i].ssum);
        for(int j = 0; j < k; j++){
            if(student[i].score[j] == -1) printf(" -");
            else printf(" %d", student[i].score[j]);
        }
        printf("\n");
    }
	return 0;
}
/*
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00003 1 0
00006 1 -1
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0

1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
6 00003 0 0 - - -
*/
