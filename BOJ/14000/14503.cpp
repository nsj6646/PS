#include <iostream>
using namespace std;

int n, m;
int map[50][50];
int visited[50][50];
int dx[] = { 0,1,0,-1 };	//북,동,남,서
int dy[] = { -1,0,1,0 };	//북,동,남,서
int ans;

/*
1.현재 위치를 청소한다.
2.현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
	- 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
	- 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
	- 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
	- 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
*/
int left(int d) {
	switch (d)
	{
	case 0:
		return 3;
	case 1:
		return 0;
	case 2:
		return 1;
	case 3:
		return 2;
	}
}
void go(int x, int y, int d,int flag,int cnt) {
	switch(flag){
	case 1:
		//1.현재 위치를 청소한다.
		if (visited[y][x]==0) {
			ans += 1;
			visited[y][x] = ans;
			//for (int i = 0; i < n; i++) {
			//	for (int j = 0; j < m; j++) {
			//		if (map[i][j] == 1) {
			//			printf("%3d",1);
			//		}
			//		else {
			//			printf("%3d",visited[i][j]);
			//		}
			//	}
			//	cout << '\n';
			//}
			//cout << '\n';
		}
	case 2:
		//2.현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
		for (int k = cnt; k < 4; k++) {
			int ld = left(d);
			int nx = x + dx[ld];
			int ny = y + dy[ld];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				//2-1. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
				if (visited[ny][nx]==0 && map[ny][nx] != 1) {
					go(nx, ny, ld, 1,cnt);
				}
				//2-2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
				else {
					d = ld;
					continue;
				}
			}			
		}
		//2-3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
		int bx = x - dx[d];
		int by = y - dy[d];
		if (bx >= 0 && bx < m && by >= 0 && by < n) {
			if (map[by][bx] != 1) {
				go(bx, by, d, 2, cnt);
			}
			//2-4. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
			else {
				cout << ans;
				exit(0);
			}
		}	
	}
}
int main()
{
	//입력
	cin >> n >> m;
	int r, c, d;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	go(c, r, d, 1,0);
	return 0;
}
