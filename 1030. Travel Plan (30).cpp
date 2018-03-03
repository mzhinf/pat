/*
	*�����· �ж����� len cost

*/
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

//----- �����·�㷨 �����1-n ʹ��ǰ memset(cost, 0x3f, sizeof(cost));
const int MAX_V = 505;		//��󶥵���
const int INF = 0x3f3f3f3f;
int cost[MAX_V][MAX_V]; 	//cost[u][v]��ʾ��e=(u,v)�Ļ��� (������ʱ����ΪINF)
int len[MAX_V][MAX_V];		//len[u][v]��ʾ��e=(u,v)��Ȩֵ (������ʱ����ΪINF)
int d[MAX_V];				//����s��������̾���
int s[MAX_V];				//��s��i�����ٷ���
bool used[MAX_V];			//�Ѿ�ʹ�ù���ͼ
int V;						//������
int pre[MAX_V];				//���·��ǰ�� ��ǰ��������Ϊ-1

//��s������������������·

void dijkstra(int st, int ed){
	//����d������ֵΪINF
	memset(d, 0x3f, sizeof(d));
	//����s������ֵΪINF
	memset(s, 0x3f, sizeof(s));
	//����user����ֵΪfalse
	memset(used, 0, sizeof(used));
	//����prev��ֵΪ-1
	for(int i = 1; i <= V; i++) pre[i] = -1;
	//s���������̾���Ϊ0
	d[st]=0;
	s[st]=0;
	while (true) {
		int v = -1;
		//��δʹ�õĵ���ѡ��һ��������С�Ķ���
		//v==-1ʱ ��ֱ��ѡ��һ�� u
		for (int u = 0; u < V; u++) {
			if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}

		if (v == ed) break;

		used[v] = true;

		for (int u = 0; u < V; u++) {
			if (d[u] > d[v] + len[v][u]){
				d[u] = d[v] + len[v][u];
				s[u] = s[v] + cost[v][u];
				pre[u] = v;
			} else if(d[u] == d[v] + len[v][u]) {
				if(s[u] > s[v] + cost[v][u]){
					d[u] = d[v] + len[v][u];
					s[u] = s[v] + cost[v][u];
					pre[u] = v;
				}
			}
		}
	}
}
//-----

int main(){
	int N, M, S, D, a, b, l, c;
	//��ʼ��
	memset(cost, 0x3f, sizeof(cost));
	memset(len, 0x3f, sizeof(len));
	scanf("%d%d%d%d", &N, &M, &S, &D);
	for(int i = 0; i < M; i++){
		scanf("%d%d%d%d", &a, &b, &l, &c);
		//��ͼΪ����ͼ Ӧ������˫������
		len[a][b] = len[b][a] = l;
		cost[a][b] = cost[b][a] = c;
	}
	V = N;
	dijkstra(S, D);
	stack<int> output;
	output.push(D);
	for (int t = D; t != S; t = pre[t]) {
		output.push(pre[t]);
	}
	while(!output.empty()){
        printf("%d ", output.top());
        output.pop();
	}
	printf("%d %d\n", d[D], s[D]);
	return 0;
}
