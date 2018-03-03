#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int value[100005];
int tnext[100005];

struct Point{
    int add;
    int v;
}smap[100005];

bool cmp(const Point &a, const Point &b){
    return a.v < b.v;
}

int main(){
    int n, head, add, v, nex, num = 0;
    memset(value, 0x3f , sizeof(value));
    memset(tnext, 0 , sizeof(tnext));
    scanf("%d%d", &n, &head);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &add, &v, &nex);
        value[add] = v;
        tnext[add] = nex;
    }
    //抽取链表
    add = head;
    while(add != -1 && value[add] != INF){
        smap[num].add = add;
        smap[num].v = value[add];
        num++;
        add = tnext[add];
    }
    sort(smap, smap + num, cmp);
    if(num != 0){
        printf("%d %05d\n", num, smap[0].add);
        for(int i = 0; i < num; i++){
            printf("%05d %d ", smap[i].add, smap[i].v);
            if(i + 1 == num) printf("-1\n");
            else printf("%05d\n", smap[i + 1].add);
        }
    } else {
        if (head==-1)printf("0 -1\n");
        else printf("0 %05d", head);
    }
    return 0;
}
/*
//全部
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345

//部分
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 -1

//根 -1
5 -1
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345

//根 不存在
5 00001
11111 100 -1
00002 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345


5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 100 12345
*/
