#include <iostream>
#include <queue>
using namespace std;

bool check[100001];
int dist[100001];
int bfs(int x, int k) {
	if (k <= x) {
		return x - k;
	}
	queue<int> q;
	q.push(x);
	check[x] = true;
	dist[x] = 0;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (x - 1 >= 0) {
			if (!check[x - 1]) {
				q.push(x - 1);
				check[x - 1] = true;
				dist[x - 1] = dist[x] + 1;
			}
		}

		if (x < k) {
			if (!check[x + 1]) {
				q.push(x + 1);
				check[x + 1] = true;
				dist[x + 1] = dist[x] + 1;
			}
			if (x * 2 <= 100000) {
				if (!check[x * 2]) {
					q.push(x * 2);
					check[x * 2] = true;
					dist[x * 2] = dist[x] + 1;
				}
			}
		}
		if (q.front() == k) {
			return dist[k];
		}
	}

}
int main()
{
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k);
	return 0;
}