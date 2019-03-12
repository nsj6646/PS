#define N		100005
#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

int n, k;
int visited[N];

queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	memset(visited, -1, sizeof(visited));

	int t = 0;

	q.push(n);
	visited[n] = 1;
	while (!q.empty()) {
		int sz = q.size();
		++t;
		while (sz--) {
			int now = q.front();
			q.pop();

			if (now == k) {
				cout << t - 1 << '\n';
				break;
			}

			int next;
			next = now - 1;
			if (next >= 0) {
				if (visited[next] == -1) {
					visited[next] = now;
					q.push(next);
				}
			}
			next = now + 1;
			if (next <=N) {
				if (visited[next] == -1) {
					visited[next] = now;
					q.push(next);
				}
			}
			next = now*2;
			if (next <= N) {
				if (visited[next] == -1) {
					visited[next] = now;
					q.push(next);
				}
			}
		}
	}
	int pos = k;
	stack<int> stk;
	while (pos != n) {
		stk.push(pos);
		pos = visited[pos];
	}
	stk.push(n);
	while (!stk.empty()) {
		cout << stk.top() << ' ';
		stk.pop();
	}
	return 0;
}