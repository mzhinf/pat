#include <cstdio>

int preorder[1005];
int postorder[1005];
int num;
int value[1005];
int left[1005];
int right[1005];

void init(int n){//O(n)
    num = 0;
    for(int i = 0; i < n; i++){
        left[i] = right[i] = -1;
    }
}

void insert_node(int v){//O(n)
    int fa = 0;
    while(true){
        if(value[fa] > v){//left
            if(left[fa] == -1){
                left[fa] = num;
                break;
            }
            fa = left[fa];
        } else {//right
            if(right[fa] == -1){
                right[fa] = num;
                break;
            }
            fa = right[fa];
        }
    }
    value[num++] = v;
}

bool flag = true;
void bst_pre(int root){
    if(!flag) return ;
    //root
    if(value[root] != preorder[num++]){
        flag = false;
        return ;
    }
    //left
    if(left[root] != -1) bst_pre(left[root]);
    //right
    if(right[root] != -1) bst_pre(right[root]);
}

void mirror_pre(int root){
    if(!flag) return ;
    //root
    if(value[root] != preorder[num++]){
        flag = false;
        return ;
    }
    //right
    if(right[root] != -1) mirror_pre(right[root]);
    //left
    if(left[root] != -1) mirror_pre(left[root]);
}

void bst_post(int root){
    //left
    if(left[root] != -1) bst_post(left[root]);
    //right
    if(right[root] != -1) bst_post(right[root]);
    //root
    postorder[num++] = value[root];
    //printf("%d", value[root]);
}

void mirror_post(int root){
    //right
    if(right[root] != -1) mirror_post(right[root]);
    //left
    if(left[root] != -1) mirror_post(left[root]);
    //root
    postorder[num++] = value[root];
    //printf("%d", value[root]);
}


int main(){
    int n;
    scanf("%d", &n);
    init(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &preorder[i]);
        if(i != 0)insert_node(preorder[i]);
        else value[num++] = preorder[i];
    }
    flag = true; num = 0;
    bst_pre(0);
    if(flag){
        num = 0;
        bst_post(0);
    } else {
        flag = true; num = 0;
        mirror_pre(0);
        if(flag){
            num = 0;
            mirror_post(0);
        }
    }
    if(flag){
        printf("YES\n");
        printf("%d", postorder[0]);
        for(int i = 1; i < n; i++) printf(" %d", postorder[i]);
        printf("\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
/**
    preorder: root left right
    postorder: left right root
    Binary Search Tree: root > left && root <= right
    Mirror Image of a BST: root <= left && root > right
*/
