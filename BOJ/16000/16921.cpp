#include <bits/stdc++.h>
using namespace std;

int a[4] = { 1,5,10,50 };
bool visited[1001];
queue<int> q;
unsigned long long  ans;
int bfs(int n) {
	for (int i = 0; i < 4; ++i) {
		q.push(a[i]);
	}
	for (int i = 0; i < n - 1; ++i) {
		int sz = q.size();
		memset(visited, false, sizeof(visited));
		while (sz--) {
			int now = q.front();
			q.pop();
			for (int k = 0; k < 4; ++k) {
				int next = now + a[k];
				if (!visited[next]) {
					q.push(next);
					visited[next] = 1;
				}
			}
		}
	}
	return q.size();
}
int main()
{
	int n;
	cin >> n;

	if(n>11){
		ans=bfs(11);
		n -= 11;
		ans += 49ULL * n;
	}
	else {
		ans = bfs(n);
	}
	cout << ans;
	return 0;
}