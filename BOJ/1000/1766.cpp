#include <iostream>
#include <queue>
#include <vector>
#define N 32001
using namespace std;

vector<int> a[N];
int ind[N];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		ind[y] += 1;
	}
	priority_queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(-i);
		}
	}
	while (!q.empty()) {
		int x = -q.top();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			ind[y] -= 1;
			if (ind[y] == 0) {
				q.push(-y);
			}
		}
	}
	return 0;
}