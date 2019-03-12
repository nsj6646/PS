#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

char maze[1000][1001];
int visited[1000][1000];
int fire[1000][1000];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
typedef pair<int, int> point;
void init(int w, int h) {
	for (int i = 0; i < h; i++) {
		memset(visited[i], 0, sizeof(int)*w);
		memset(fire[i], 0, sizeof(int)*w);
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int w, h;
		cin >> w >> h;
		init(w, h);
		point j, f;
		queue<point> jq, fq;
		for (int i = 0; i < h; i++) {
			cin >> maze[i];
			for (int j = 0; j < w; j++) {
				if (maze[i][j] == '@') {
					visited[i][j] = 1;
					jq.push({ i,j });
				}
				else if (maze[i][j] == '*') {
					fire[i][j] = 1;
					fq.push({ i,j });
				}
			}
		}

		while (!fq.empty()) {
			point nowF = fq.front();
			fq.pop();
			int x = nowF.first;
			int y = nowF.second;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < h&&ny >= 0 && ny < w&&maze[nx][ny] != '#') {
					if (fire[nx][ny] == 0) {
						fire[nx][ny] = fire[x][y] + 1;
						fq.push({ nx,ny });
					}
				}
			}
		}
		cout << '\n';
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << fire[i][j] << ' ';
			}
			cout << '\n';
		}


		while (!jq.empty()) {
			point nowJ = jq.front();
			jq.pop();
			int x = nowJ.first;
			int y = nowJ.second;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < h&&ny >= 0 && ny < w&&maze[nx][ny] != '#') {
					if (visited[nx][ny] == 0 && (fire[nx][ny] == 0 || fire[nx][ny] > visited[x][y] + 1)) {
						visited[nx][ny] = visited[x][y] + 1;
						jq.push({ nx,ny });
					}
				}
			}
		}
		cout << '\n';
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << visited[i][j] << ' ';
			}
			cout << '\n';
		}

		int ans = 0x7fffffff;
		bool isescape = false;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
					if (visited[i][j] > 0) {
						ans = min(ans, visited[i][j]);
						isescape = true;
					}
				}
			}
		}
		if (isescape) {
			cout << ans << '\n';
		}
		else {
			cout << "IMPOSSIBLE\n";
		}
	}
	return 0;
}