#include <iostream>
#include <vector>
#include <queue>
#define N 100001
using namespace std;

typedef pair<int, int> vertex;
typedef pair<int, vertex> edge;

int parent[N];

/*mst - 3���� �۾� 
1. init() : parent�� ��Ʈ �迭�� �ʱ�ȭ���ִ� �۾�
2. find()
3. merge()
*/


int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x]=find(parent[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return false;
	}
	else {
		parent[y] = x;
		return true;
	}
}
int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	/*init*/
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	priority_queue<edge> pq;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ -c,{a,b} });
	}
	int ans = 0;
	int cnt = 0;
	while (!pq.empty()) {
		edge e = pq.top();
		pq.pop();
		int w = -e.first;
		int x = e.second.first;
		int y = e.second.second;
		if (merge(x, y)) {
			ans += w;
			cnt += 1;
		}
		if (cnt == n - 1) {
			break;
		}
	}
	cout << ans;
	return 0;
}