#include <iostream>
#include <queue>
using namespace std;

int n, k;
int visited[100001];
int plus1(int x) {
	return x + 1;
}
int minus1(int x) {
	return x - 1;
}
int mul2(int x) {
	return 2 * x;
}
int(*d[3])(int) = { plus1,minus1,mul2 };

int main()
{
	cin >> n >> k;
	for (int i = 0; i <= 100000; i++) {
		visited[i] = -1;
	}
	int ans = 1;
	queue<int> q;
	q.push(n);
	visited[n] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nx = d[i](x);
			if (nx >= 0 && nx <= 100000) {
				if (nx == k) {
					if (visited[k] == -1 || visited[k] > visited[x] + 1) {
						visited[k] = visited[x] + 1;
						ans = 1;
					}
					else if (visited[k] == visited[x] + 1) {
						ans += 1;
					}
				}
				else if (visited[nx] == -1 || visited[nx] >= visited[x] + 1) {
					visited[nx] = visited[x] + 1;
					q.push(nx);
				}
			}
		}
	}
	cout << visited[k] << '\n' << ans;
	return 0;
}

