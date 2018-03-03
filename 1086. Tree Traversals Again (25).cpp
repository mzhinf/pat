#include <cstdio>
#include <cstring>

struct Node{
    int fa;
    int left;
    int right;
    int isPop;
}node[35];

void init(int n){
    for(int i = 1; i <= n; i++){
        node[i].fa = node[i].isPop = -1;
        node[i].left = node[i].right = -1;
    }
}

int st;
void postorder(int e){
    if(node[e].left != -1) postorder(node[e].left);
    if(node[e].right != -1) postorder(node[e].right);
    printf("%d%c", e, e == st ? '\n' : ' ');
}

int main(){
    int n, p = -1, v;
    char str[5];
    scanf("%d", &n);
    init(n);
    for(int i = 0; i < n * 2; i++){
        scanf("%s", str);
        if(strcmp("Push", str) == 0){
            scanf("%d", &v);
            if(p == -1){
                st = v;
            } else {
                if(node[p].isPop == -1){
                    node[p].left = v;
                    node[v].fa = p;
                } else {
                    node[p].right = v;
                    node[v].fa = p;
                }
            }
            p = v;
        } else {
            while(node[p].isPop == 1) p = node[p].fa;
            node[p].isPop = 1;
            //printf("%d\n", p);
        }
    }
    //printf("%d\n", p);
    postorder(st);
    return 0;
}
/*
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
3 4 2 6 5 1

4
Push 1
Pop
Push 2
Pop
Push 3
Push 4
Pop
Pop
4 3 2 1

6
Push 2
Push 1
Push 3
Push 4
Push 5
Push 6
Pop
Pop
Pop
Pop
Pop
Pop
6 5 4 3 1 2
*/
