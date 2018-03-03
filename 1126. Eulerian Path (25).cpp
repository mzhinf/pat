#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> smap;
vector<bool> vis;
int cnt;

void dfs(int st){
    vis[st] = true;
    cnt++;//��¼����node����
    for(vector<int>::iterator it = smap[st].begin();
        it != smap[st].end(); it++){
        if(!vis[*it]) dfs(*it);
    }
    return ;
}

int main(){
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    smap.resize(n + 1);
    vis.resize(n + 1, false);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        smap[a].push_back(b);
        smap[b].push_back(a);
    }
    //�жϸ�ͼ�Ƿ���ͨ
    cnt = 0;
    dfs(1);
    //�жϸ�������Ƿ�Ϊ����������
    int odd = 0;
    for(int i = 1; i <= n; i++){
        if(smap[i].size() % 2 == 1) odd++;
        printf("%d%c", smap[i].size(), i == n ? '\n' : ' ');
    }
    if(odd == 0 && cnt == n) printf("Eulerian\n");
    else if(odd == 2 && cnt == n) printf("Semi-Eulerian\n");
    else printf("Non-Eulerian\n");
    return 0;
}