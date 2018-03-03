#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int postorder[35];
int inorder[35];

struct Node {
	int v;
	bool have_value;
	Node *left,*right;
	Node():have_value(false),left(NULL),right(NULL){}
};

Node* newNode() { return new Node(); }

Node *post_in(int n, int *post, int *in){
	//postorder left:[0,i-1] right:[i,n-2] root:n-1
	//inorder   left:[0,i-1] root:i right:[i+1,n-1]
	//find root
	int root = post[n - 1], i = 0;
	Node *head;
	while(in[i] != root && i < n) i++;
	//root
	head = newNode();
	head -> v = root;
	head -> have_value =true;
	//left
	if(i != 0) head -> left = post_in(i, &post[0], &in[0]);
	//right
	if(n - 1 - i != 0) head -> right = post_in(n - 1 - i, &post[i], &in[i + 1]);
	return head;
}

void zigzagging(Node* head){
    queue<Node *> q, tq;
    queue<int> lr;
    stack<int> rl;
    bool type = true;//true:L->R false:R->L
    printf("%d", head->v);
    if(head->left != NULL) tq.push(head->left);
    if(head->right != NULL) tq.push(head->right);
    while(!tq.empty()){
        q = tq;
        tq = queue<Node *>();
        while(!q.empty()){
            Node *temp = q.front(); q.pop();
            if(temp->left != NULL) tq.push(temp->left);
            if(temp->right != NULL) tq.push(temp->right);
            if(type) lr.push(temp->v);
            else rl.push(temp->v);
        }
        if(type){
            while(!lr.empty()){
                printf(" %d", lr.front()); lr.pop();
            }
        } else {
            while(!rl.empty()){
                printf(" %d", rl.top()); rl.pop();
            }
        }
        type = !type;
    }
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &inorder[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &postorder[i]);
	}
	Node *head = post_in(n, postorder, inorder);
	zigzagging(head);
	return 0;
}
