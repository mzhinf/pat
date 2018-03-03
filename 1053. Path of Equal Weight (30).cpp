/**
	可以使用dfs比bfs更快 无需存储所有的情况 可以直接顺序输出结果
	
    *最后一个case不过
    排序算法有错
    增加一个唯一序列id区分相同的sum序列
*/
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int weight[105];
int sumW[105];
int fa[105];
vector<int> son[105];

vector<int> q, tq;
vector<int>::iterator qit, vit;
stack<int> out;

struct Sequence{
    int id;
    vector<int> seq;
    void print(){
        vector<int>::iterator it = seq.begin();
        printf("%d", *it);
        for(it++; it != seq.end(); it++){
            printf(" %d", *it);
        }
        printf("\n");
    }
    bool operator < (Sequence a){
        vector<int>::iterator it = seq.begin(), ait = a.seq.begin();
        for(; it != seq.end() && ait != a.seq.end(); it++, ait++){
            //printf("it:%d ait:%d", *it, *ait);
            if(*it != *ait) return *it > *ait;
        }
        return id < a.id;
    }
};
vector<Sequence> sequence;
vector<Sequence>::iterator sit;
int id = 0;

void seqInsert(int sp){
    Sequence temp;
    temp.id = id; id++;
    while(sp != -1){
        out.push(sp);
        sp = fa[sp];
    }
    while(!out.empty()){
        sp = out.top(); out.pop();
        temp.seq.push_back(weight[sp]);
    }
    sequence.push_back(temp);
}

int main(){
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 0; i < n; i++){
        scanf("%d", &weight[i]);
    }
    for(int i = 0; i < m; i++){
        int v, k, temp;
        scanf("%d%d", &v, &k);
        while(k--){
            scanf("%d", &temp);
            son[v].push_back(temp);
            fa[temp] = v;
        }
    }
    tq.push_back(0);//push root
    sumW[0] = weight[0];
    fa[0] = -1;
    while(!tq.empty()){
        q = tq;
        tq.clear();
        for(qit = q.begin(); qit != q.end(); qit++){
            int tw = sumW[*qit];
            //judge leaf
            if(tw > s) continue;
            if(son[*qit].empty()){
                if(tw == s)seqInsert(*qit);
                continue;
            }
            for(vit = son[*qit].begin(); vit != son[*qit].end(); vit++){
                sumW[*vit] = tw + weight[*vit];
                tq.push_back(*vit);
            }
        }
    }

    sort(sequence.begin(), sequence.end());

    for(sit = sequence.begin(); sit != sequence.end(); sit++){
        (*sit).print();
    }
    return 0;
}

/**
100 1 2
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 99  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99

*/
