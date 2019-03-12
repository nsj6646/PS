#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

typedef struct point {
	int x, y;
}point;
string field[12];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans;

void move() {
	for (int i = 11; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (field[i][j] == '.') {
				for (int k = i; k >= 0; k--) {
					if (field[k][j] != '.') {
						field[i][j] = field[k][j];
						field[k][j] = '.';
						break;
					}
				}
			}
		}
	}
}

void simulate() {
	if (field[11] == "......") {
		return;
	}
	bool visited[12][6] = { false };
	bool iscombo = false;
	for (int i = 11; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (field[i][j] != '.' && !visited[i][j]) {
				queue<point> q;
				vector<point> v;
				q.push({ j,i });
				visited[i][j] = true;
				v.push_back({ j,i });
				int puyo = 1;
				while (!q.empty()) {
					point now = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = now.x + dx[k];
						int ny = now.y + dy[k];
						if (nx >= 0 && nx < 6 && ny >= 0 && ny < 12) {
							if (!visited[ny][nx] && field[ny][nx] == field[now.y][now.x]) {
								q.push({ nx,ny });
								visited[ny][nx] = true;
								v.push_back({ nx,ny });
								puyo += 1;
							}
						}
					}
				}
				if (puyo >= 4) {
					iscombo = true;
					for (auto &p : v) {
						field[p.y][p.x] = '.';
					}
				}
			}
		}
	}
	if (!iscombo) {
		return;
	}
	ans += 1;
	move();
	simulate();
}
int main()
{
	for (int i = 0; i < 12; i++) {
		cin >> field[i];
	}
	simulate();
	cout << ans;
	return 0;
}


//
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//char puyo[12][6];
//bool visit[12][6];
//
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//
//struct puyo1 {
//	int x;
//	int y;
//	char color;
//	int cnt;
//};
//
//queue<puyo1> q;
//
//bool change;
//
//void init() {
//	for (int i = 0; i < 12; i++) {
//		for (int j = 0; j < 6; j++) {
//			cin >> puyo[i][j];
//		}
//	}
//	return;
//}
//
//void bfs(int x, int y, char color, int cnt) {
//	q.push({ x, y, color, cnt });
//	visit[x][y] = true;
//
//	while (!q.empty()) {
//		x = q.front().x;
//		y = q.front().y;
//		color = q.front().color;
//		cnt = q.front().cnt;
//
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//
//			if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6
//				&& visit[nx][ny] == false && puyo[nx][ny] == color) {
//				q.push({ nx,ny,color,cnt + 1 });
//				visit[nx][ny] = true;
//			}
//		}
//
//	}
//	int cnt2 = 0;
//	for (int i = 0; i < 12; i++) {
//		for (int j = 0; j < 6; j++) {
//			if (visit[i][j] == true)
//				cnt2++;
//		}
//	}
//
//	if (cnt2 >= 4) {
//		change = true;
//		for (int i = 0; i < 12; i++) {
//			for (int j = 0; j < 6; j++) {
//				if (visit[i][j] == true) {
//					puyo[i][j] = '.';
//				}
//			}
//		}
//	}
//	for (int i = 0; i < 12; i++) {
//		for (int j = 0; j < 6; j++) {
//			visit[i][j] = false;
//		}
//	}
//
//	return;
//}
//
//int main() {
//
//	init();
//
//	int cnt_combo = 0;
//	int cnt_combo2 = 0;
//
//	while (1) {
//		cnt_combo2 = cnt_combo;
//
//		for (int i = 0; i < 12; i++) {
//			for (int j = 0; j < 6; j++) {
//				if (puyo[i][j] != '.'&& visit[i][j] == false) {
//					bfs(i, j, puyo[i][j], 1);
//				}
//			}
//		}
//
//		for (int i = 11; i >= 0; i--) {
//			for (int j = 0; j < 6; j++) {
//				if (puyo[i][j] == '.') {
//					for (int k = i - 1; k >= 0; k--) {
//						if (puyo[k][j] != '.') {
//							puyo[i][j] = puyo[k][j];
//							puyo[k][j] = '.';
//							break;
//						}
//					}
//				}
//			}
//		}
//
//		if (change == true) {
//			cnt_combo++;
//			change = false;
//		}
//
//		if (cnt_combo2 == cnt_combo)
//			break;
//
//	}
//
//	cout << cnt_combo << '\n';
//	return 0;
//}
//
//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//
//char arr[13][7];
//bool visit[13][7];
//int dx[4] = { -1,1,0,0 };
//int dy[4] = { 0,0,-1,1 };
//int combo;
//int chain;
//typedef struct loc {
//	int x;
//	int y;
//};
//loc lc;
//queue<loc> que;
//queue<loc> del;
//int result[18];
//int idx;
//
//void init() {
//	for (int i = 0; i < 12; i++)
//		for (int j = 0; j < 6; j++)
//			visit[i][j] = false;
//
//	for (int i = 11; i >= 0; i--) {
//		for (int j = 0; j < 6; j++) {
//			if (arr[i][j] == '.') {
//				int temp = -1;
//				while (i + temp >= 0) {
//					if (arr[i + temp][j] != '.') {
//						arr[i][j] = arr[i + temp][j];
//						arr[i + temp][j] = '.';
//						break;
//					}
//					temp--;
//				}
//			}
//		}
//	}
//}
//
//int main() {
//	for (int i = 0; i < 12; i++)
//		for (int j = 0; j < 6; j++)
//			cin >> arr[i][j];
//
//	for (int i = 11; i >= 0; i--) {
//		for (int j = 0; j < 6; j++) {
//			if (arr[i][j] != '.' && !visit[i][j]) {
//				lc.x = i, lc.y = j;
//				que.push(lc);
//				del.push(lc);
//				visit[i][j] = true;
//				while (!que.empty()) {
//					int x1 = que.front().x;
//					int y1 = que.front().y;
//					que.pop();
//					combo++;
//					for (int k = 0; k < 4; k++) {
//						if (x1 + dx[k] >= 0 && x1 + dx[k] < 12 && y1 + dy[k] >= 0 && y1 + dy[k] < 6 && arr[x1][y1] == arr[x1 + dx[k]][y1 + dy[k]] && !visit[x1 + dx[k]][y1 + dy[k]]) {
//							lc.x = x1 + dx[k];
//							lc.y = y1 + dy[k];
//							que.push(lc);
//							del.push(lc);
//							visit[lc.x][lc.y] = true;
//						}
//					}
//				}
//				if (combo >= 4) {
//					result[idx] = 1;
//					while (!del.empty()) {
//						arr[del.front().x][del.front().y] = '.';
//						del.pop();
//					}
//				}
//				else {
//					while (!del.empty()) {
//						del.pop();
//					}
//				}
//
//				combo = 0;
//			}
//		}
//		if (i == 0) { // 맵 한번의 탑색 및 뿌요 제거 완료
//			if (result[idx] == 1) {
//				init();
//				/*cout << '\n';
//				for (int a = 0; a < 12; a++) {
//				for (int b = 0; b < 6; b++) {
//				cout << arr[a][b];
//				}
//				cout << '\n';
//				}*/
//				idx++;
//				i = 12;
//			}
//			else {
//				for (int h = 0; h < 18; h++)
//					chain += result[h];
//				cout << chain;
//				return 0;
//			}
//		}
//	}
//	return 0;
//}
