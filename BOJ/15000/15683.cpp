#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct cctv
{
	int x, y;
	int num;
	int dir;
	cctv(int x = 0, int y = 0, int n = 0,int d=0) :x(x), y(y), num(n),dir(d) {}
};
int n, m;

vector<cctv> tvs;
int dx[6][4][4]{	//몇번 카메라가 어느방향을 보고있을 때 x(상:0, 우:1, 하:2, 좌:3)
	{ {0} },
	{ { -1,0,0,0 },{ 0,0,0,0 },{ 0,0,1,0 },{ 0,0,0,0 }},	//1
	{ { 0,0,0,0 },{ -1,0,1,0 }},	//2
	{ { -1,0,0,0 },{ 0,0,1,0 },{ 0,0,1,0 },{ -1,0,0,0 } },	//3
	{ { -1,0,0,0 },{ -1,0,1,0 },{ 0,0,1,0 },{ -1,0,1,0 } },	//4
	{ { -1,0,1,0 }},	//5
};
int dy[6][4][4]{	//몇번 카메라가 어느방향을 보고있을 때 y(상:0, 우:1, 하:2, 좌:3)
	{ { 0 } },
	{ { 0,0,0,0 },{ 0,1,0,0 },{ 0,0,0,0 },{ 0,0,0,-1 } },	//1
	{ { 0,1,0,-1 },{ 0,0,0,0 } },	//2
	{ { 0,1,0,0 },{ 0,1,0,0 },{ 0,0,0,-1 },{ 0,0,0,-1 } },	//3
	{ { 0,1,0,-1 },{ 0,1,0,0 },{ 0,1,0,-1 },{ 0,0,0,-1 } },	//4
	{ { 0,1,0,-1 } },	//5
};
int a[8][8];
int save[8][8];

int ans;
int check(){
	memcpy(save, a, sizeof(save));
	for (int i = 0; i < tvs.size(); i++) {
		int x = tvs[i].x;
		int y = tvs[i].y;
		save[x][y] = 9;
		int num = tvs[i].num;
		int d = tvs[i].dir;
		for (int k = 0; k < 4; k++) {
			if (dx[num][d][k] == 0 && dy[num][d][k] == 0) {
				continue;
			}
			int nx = x + dx[num][d][k];
			int ny = y + dy[num][d][k];
			while (nx >= 0 && nx < n&&ny >= 0 && ny < m&&a[nx][ny] != 6) {
				save[nx][ny] = 9;
				nx += dx[num][d][k];
				ny += dy[num][d][k];
			}
		}
	}
	int cnt = 0;
	//printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//printf("%d ", save[i][j]);
			if (save[i][j] ==0) {
				cnt += 1;
			}
		}
		//printf("\n");
	}
	return cnt;
}
void simulate(int i) {
	if (i == tvs.size()) {
		int t = check();
		ans = t < ans ? t : ans;
		return;
	}
	for (int k = 0; k < 4; k++) {
		if ((tvs[i].num == 2&&k>2)||(tvs[i].num==5&&k>1)) {
			continue;
		}
		tvs[i].dir = k;
		simulate(i + 1);
	}
	return;
}
int main()
{
	scanf("%d %d", &n, &m);
	ans = n * m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] >= 1 && a[i][j] <= 5) {
				tvs.push_back({ i,j,a[i][j],0 });
			}
		}
	}

	simulate(0);
	printf("%d", ans);

	return 0;
}