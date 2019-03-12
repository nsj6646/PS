#include <iostream>
#include <deque>
#include <cstring>

#define N 11

using namespace std;

int a[N][N];
int save[N][N];
deque<int> trees[N][N];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

int n, m, k;
int ans;
bool safe(int x, int y) {
	return (x >= 1 && x <= n && y >= 1 && y <= n);
}
void spring() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			deque<int> &tree = trees[i][j];
			if (tree.empty()) continue;
			for (int t = 0; t<tree.size(); t++) {
				if (a[i][j] >= tree[t]) {
					a[i][j] -= tree[t];
					tree[t] += 1;
				}
				else {
					int ts = tree.size();
					for (; t < ts; t++) {
						/*summer*/
						a[i][j] += tree.back() / 2;
						tree.pop_back();
						ans -= 1;
					}
				}
			}
		}
	}
}
void fall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			/*winter*/
			a[i][j] += save[i][j];
			deque<int> &tree = trees[i][j];
			if (tree.empty()) continue;
			for (int t = 0; t<tree.size(); t++) {
				if (tree[t] % 5 == 0) {
					for (int d = 0; d < 8; d++) {
						int nx = i + dx[d];
						int ny = j + dy[d];
						if (safe(nx, ny)) {
							trees[nx][ny].push_front(1);
							ans += 1;
						}
					}
				}
			}
		}
	}
}

void simulate() {
	for (int i = 0; i < m; i++) {
		spring();
		//summer();
		fall();
		//winter();
	}
}
int main()
{
	ios::sync_with_stdio(false);

	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> save[i][j];
			a[i][j] = 5;
			//dtree[i][j] = 0;
			trees[i][j].clear();
		}
	}

	for (int i = 0; i < k; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		trees[x][y].push_back(age);
		ans += 1;
	}

	/*simulate*/
	simulate();

	cout << ans;
	return 0;
}