#include <cstdio>
#define INFI 0x7fffffff
using namespace std;

struct coin {
	int x, y;
	coin(int x = 0, int y = 0) :x(x), y(y) {}
};
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
coin c[2];
int n, m;
char a[20][21];

int ans = -1;
void simulate(int cnt) {
	if (cnt > 10) {
		return;
	}


	for (int k = 0; k < 4; k++) {
		int fall = 0;
		int wall = 0;
		int x[2], y[2];
		int nx[2], ny[2];
		for (int i = 0; i < 2; i++) {
			x[i] = c[i].x;
			y[i] = c[i].y;
			nx[i] = x[i] + dx[k];
			ny[i] = y[i] + dy[k];
			if (nx[i] < 0 || nx[i] >= n || ny[i] < 0 || ny[i] >= m) {
				fall += 1;
			}
			else {
				if (a[nx[i]][ny[i]] == '#') {
					wall += 1;
					nx[i] = x[i];
					ny[i] = y[i];
				}
			}
		}
		if (wall == 2) {
			/*둘다 벽에 부딫히는건 의미없음.*/
			continue;
		}
		if (fall == 1) {
			/*하나만 떨어졌으면 종료*/
			if (ans == -1 || ans > cnt) {
				//printf("\n%d\n", cnt);
				//printf("%d %d\n", v[0].x, v[0].y);
				//printf("%d %d\n", v[1].x, v[1].y);
				ans = cnt;
			}
			return;
		}
		else if (fall == 2) {
			/*둘다떨어졌어진건 의미없음.*/
			continue;
		}	
		else {
			/*아무것도 안떨어졌으면 한번 더 해봄*/
			if ((nx[0] == nx[1]) && (ny[0] == ny[1])) {
				/*두 동전이 같은위치가되면 어차피 나중에 같이 떨어진다.*/
				continue;
			}
			c[0].x = nx[0]; c[0].y = ny[0];
			c[1].x = nx[1]; c[1].y = ny[1];
			simulate(cnt + 1);
			c[0].x = x[0]; c[0].y = y[0];
			c[1].x = x[1]; c[1].y = y[1];
		}
	}
}
int main()
{
	
	scanf("%d %d", &n, &m);
	int idx = 0;
	for (int i = 0; i < n; i++) {	
		for (int j = 0; j < m; j++) {
			scanf(" %c", &a[i][j]);
			if (a[i][j] == 'o') {
				c[idx++] = { i,j };
			}
		}
	}

	simulate(1);
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		printf("%c", a[i][j]);
	//	}
	//	printf("\n");
	//}
	printf("%d", ans);
	return 0;
}