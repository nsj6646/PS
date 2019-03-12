#define N		100001
#define MAX_WEIGHT 1000000000
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int src, dst;
typedef pair<int, int> pii;
vector<pii> v[N];
int visited[N];
queue<int> q;
void init() {
	memset(visited, 0, sizeof(visited));
}
bool bfs(int limit) {
	init();
	q.push(src);
	visited[src] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); ++i) {
			int next = v[now][i].first;
			if (!visited[next]&& v[now][i].second >= limit) {
				q.push(next);
				visited[next] = 1;
			}
		}
	}

	return (visited[dst] == 1);
}
int main()
{
	scanf("%d  %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	
	scanf("%d %d", &src, &dst);

	int weight;
	int low = 1, high = MAX_WEIGHT,mid;
	while (low <= high) {
		mid = (low + high) / 2;
		bool result = bfs(mid);
		if (result) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	printf("%d", low - 1);




	return 0;
}



















//#include <iostream>
//#include <queue>
//#include <vector>
//#include <cstring>
//using namespace std;
//
//vector<pair<int, int>> v[10001];
//bool check[10001];
//int ans;
//bool bfs(int a, int b,int c) {
//	queue<int> q;
//	check[a] = true;
//	q.push(a);
//	while (!q.empty()) {
//		for (auto u : v[q.front()]) {
//			if (u.second >= c&&!check[u.first]) {
//				check[u.first] = true;
//				q.push(u.first);
//			}
//		}
//		q.pop();
//	}
//	return check[b];
//}
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//	int n, m;
//	cin >> n >> m;
//	
//	for (int i = 0; i < m; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		v[a].push_back(make_pair(b, c));
//		v[b].push_back(make_pair(a, c));
//	}
//	int a, b;
//	cin >> a >> b;
//	int l = 1, r = 1000000000;
//	while (l <= r) {
//		int mid = (l + r) / 2;
//		memset(check, false, sizeof(check));
//		if (bfs(a, b, mid)) {
//			l = mid + 1;
//		}
//		else {
//			r = mid - 1;
//		}
//	}
//	cout << r;
//	
//
//	return 0;
//}
//
////#include <cstdio>
////#include <vector>
////#include <cstring>
////using namespace std;
////
////vector<pair<int, int>> a[10001];
////bool c[10001];
////int n, m;
////int st, ed;
////bool go(int node, int limit) {
////	if (c[node]) {
////		return false;
////	}
////	c[node] = true;
////	if (node == ed) {
////		return true;
////	}
////	for (auto &p : a[node]) {
////		int next = p.first;
////		int cost = p.second;
////		if (cost >= limit) {
////			if (go(next, limit)) {
////				return true;
////			}
////		}
////	}
////	return false;
////}
////
////int main() {
////	scanf("%d %d", &n, &m);
////	while (m--) {
////		int x, y, z;
////		scanf("%d %d %d", &x, &y, &z);
////		a[x].push_back(make_pair(y, z));
////		a[y].push_back(make_pair(x, z));
////	}
////	scanf("%d %d", &st, &ed);
////	int left, right;
////	left = 1;
////	right = 1000000000;
////	int ans = 0;
////	while (left <= right) {
////		int mid = left + (right - left) / 2;
////		memset(c, false, sizeof(c));
////		if (go(st, mid)) {
////			ans = mid;
////			left = mid + 1;
////		}
////		else {
////			right = mid - 1;
////		}
////	}
////	printf("%d\n", ans);
////}