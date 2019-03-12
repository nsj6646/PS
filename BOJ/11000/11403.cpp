#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int a[100][100];
int visited[100];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		memset(visited, 0, sizeof(visited));
		queue<int> q;
		q.push(i);

		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int j = 0; j < n; j++) {
				if (a[x][j] == 1&&visited[j]==0) {
					q.push(j);
					visited[j] = 1;
					a[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}