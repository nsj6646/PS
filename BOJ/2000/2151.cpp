#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> point;
char house[50][51];
int visited[50][50];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void printall(int n) {
	cout << '\n';
	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; j < n; j++) {
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<point> door;

	for (int i = 0; i < n; i++) {
		cin >> house[i];
		for (int j = 0; j < n; j++) {
			if (house[i][j] == '#') {
				door.push_back({ i,j });
			}
		}
	}
	int ans = 0x7fffffff;
	queue<point> q;
	point &start = door[0];
	q.push(start);
	visited[start.first][start.second] = 1;
	while (!q.empty()) {
		int save[50][50];
		point now = q.front();
		int x = now.first;
		int y = now.second;
		q.pop();
		
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			while (nx >= 0 && nx < n&&ny >= 0 && ny < n&&house[nx][ny] != '*') {
				if (visited[nx][ny] == 0) {
					visited[nx][ny] = visited[x][y] + 1;
					if (house[nx][ny] == '!') {
						q.push({ nx,ny });
					}
				}
				nx += dx[k];
				ny += dy[k];
			}

		}
	}
	point &target = door[1];
	cout << visited[target.first][target.second] - 2;

	return 0;
}