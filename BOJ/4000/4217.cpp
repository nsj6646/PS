#include <cstdio>
#include <bitset>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int h, w;
typedef pair<int, int> point;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int a[200][401];
int visited[200][401];	//0:흰색 1:검정색 -1:방문안함
char letter[6] = { 'W','A','K','J','S','D' };

void check_bg(int i, int j) {
	queue<point> q;
	q.push({ i,j });
	visited[i][j] = 0;
	while (!q.empty()) {
		point now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < h&&ny >= 0 && ny < w) {
				if (a[nx][ny] == 0 && visited[nx][ny] == -1) {
					visited[nx][ny] = 0;
					q.push({ nx,ny });
				}
			}
		}
	}
}
void check_white(int i, int j) {
	queue<point> q;
	q.push({ i,j });
	visited[i][j] = 0;
	while (!q.empty()) {
		point now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < h&&ny >= 0 && ny < w) {
				if (a[nx][ny] == 0 && visited[nx][ny] == -1) {	//신성문자 내의 흰색체크
					visited[nx][ny] = 0;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int check_letter(int i, int j) {
	int cnt = 0;

	queue<point> q;
	q.push({ i,j });
	visited[i][j] = 1;
	while (!q.empty()) {
		point now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < h&&ny >= 0 && ny < w) {
				if (a[nx][ny] == 0 && visited[nx][ny] == -1) {	//신성문자 내의 흰색체크
					check_white(nx, ny);
					cnt += 1;
				}
				if (a[nx][ny] != 0 && visited[nx][ny] == -1) {
					visited[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	return cnt;
}
int main()
{
	for(int tc=1;;tc++){
		scanf("%d %d", &h, &w);
		if (h == 0 && w == 0)break;
		w *= 8;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j+=8) {
				int x;
				scanf("%02x", &x);
				bitset<8> b(x);
				for (int k = j; k < j + 8; k++) {
					a[i][k] = (int)b[k-j];
					visited[i][j] = -1;
				}
			}
		}

		printf("\n");
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j ++) {
				printf("%d", a[i][j]);
			}
			printf("\n");
		}

		//배경 0없애기
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
					if (a[i][j] == 0&&visited[i][j]==-1) {
						check_bg(i, j);
					}
				}
			}
		}

		vector<char> ans;
		//신성문자 체크
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] != 0&&visited[i][j]==-1) {
					ans.push_back(letter[check_letter(i, j)]);
				}
			}
		}
		sort(ans.begin(), ans.end());
		printf("Case %d: ", tc);
		for (char c : ans) {
			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}