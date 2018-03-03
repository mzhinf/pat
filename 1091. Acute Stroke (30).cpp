#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Point{
	int x, y, z;
	Point(int x, int y, int z): x(x), y(y), z(z) {}
};

bool smap[65][1300][130];
//six direction
int dx[6] = {-1, 0, 0, 1, 0, 0};
int dy[6] = {0, -1, 0, 0, 1, 0};
int dz[6] = {0, 0, -1, 0, 0, 1};
int M, N, L, T, ssum;

void init(){
	ssum = 0;
	memset(smap, 0, sizeof(smap));
}

void bfs(Point e){
	int tsum = 1;
	queue<Point> q, tq;
	tq.push(e);
	while(!tq.empty()){
		q = tq;
		tq = queue<Point>();
		while(!q.empty()){
			Point tp = q.front(); q.pop();
			int x = tp.x;
			int y = tp.y;
			int z = tp.z;
			//six dir
			for(int i = 0; i < 6; i++){
				int tx = x + dx[i];
				int ty = y + dy[i];
				int tz = z + dz[i];
				//是否在范围之内
				if(tx >= 0 && tx < L
				&& ty >= 0 && ty < M
				&& tz >= 0 && tz < N){
					//是否存在
					if(smap[tx][ty][tz]){
						Point p(tx, ty, tz);
						tq.push(p);
						smap[tx][ty][tz] = false;
						tsum++;
					}
				}
			}
		}
	}
	if(tsum >= T) ssum += tsum;
}

int main(){
    init();
	int v;
	scanf("%d%d%d%d", &M, &N, &L, &T);
	//写入数据
	for(int i = 0; i < L; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k < N; k++){
				scanf("%d", &v);
				if(v) smap[i][j][k] = true;
			}
		}
	}
	//遍历 bfs
	for(int i = 0; i < L; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k < N; k++){
				if(smap[i][j][k]){
					Point p(i, j, k);
					smap[i][j][k] = false;
					bfs(p);
				}
			}
		}
	}
	printf("%d\n", ssum);
	return 0;
}