#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

bool check[10000];

inline int D(int n) {
	return 2 * n > 9999 ? 2 * n % 10000 : 2 * n;
}
inline int S(int n) {
	return n == 0 ? 9999 : n - 1;
}
inline int L(int n) {
	return (n- (n / 1000)*1000) * 10 + n / 1000;
}
inline int R(int n) {
	return n % 10 * 1000 + n / 10;
}
string bfs(int a, int b) {
	queue<pair<int, string>> q;
	q.push({ a,"" });
	check[a] = true;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		if (now.first == b) {
			return now.second;
		}		
		int d = D(now.first), s = S(now.first), l = L(now.first), r = R(now.first);
		if (!check[d]) {
			q.push({ d, now.second + "D" });
			check[d] = true;
		}
		if (!check[s]) {
			q.push({ s,now.second + "S" });
			check[s] = true;
		}
		if (!check[l]) {
			q.push({ l,now.second + "L" });
			check[l] = true;
		}
		if (!check[r]) {
			q.push({ r,now.second + "R" });
			check[r] = true;
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(check, false, sizeof(check));
		int a, b;
		cin >> a >> b;

		cout << bfs(a, b) << '\n';
	}
	return 0;
}