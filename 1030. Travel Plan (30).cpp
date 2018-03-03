/*
	*裸最短路 判断条件 len cost

*/
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

//----- 裸最短路算法 顶点从1-n 使用前 memset(cost, 0x3f, sizeof(cost));
const int MAX_V = 505;		//最大顶点数
const int INF = 0x3f3f3f3f;
int cost[MAX_V][MAX_V]; 	//cost[u][v]表示边e=(u,v)的花费 (不存在时设置为INF)
int len[MAX_V][MAX_V];		//len[u][v]表示边e=(u,v)的权值 (不存在时设置为INF)
int d[MAX_V];				//顶点s出发的最短距离
int s[MAX_V];				//从s到i的最少费用
bool used[MAX_V];			//已经使用过的图
int V;						//顶点数
int pre[MAX_V];				//最短路的前驱 无前驱则设置为-1

//从s出发到各个顶点的最短路

void dijkstra(int st, int ed){
	//设置d中所有值为INF
	memset(d, 0x3f, sizeof(d));
	//设置s中所有值为INF
	memset(s, 0x3f, sizeof(s));
	//设置user所有值为false
	memset(used, 0, sizeof(used));
	//设置prev的值为-1
	for(int i = 1; i <= V; i++) pre[i] = -1;
	//s到本身的最短距离为0
	d[st]=0;
	s[st]=0;
	while (true) {
		int v = -1;
		//从未使用的点钟选择一个距离最小的顶点
		//v==-1时 先直接选择一个 u
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
	//初始化
	memset(cost, 0x3f, sizeof(cost));
	memset(len, 0x3f, sizeof(len));
	scanf("%d%d%d%d", &N, &M, &S, &D);
	for(int i = 0; i < M; i++){
		scanf("%d%d%d%d", &a, &b, &l, &c);
		//改图为无向图 应该输入双向数据
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
