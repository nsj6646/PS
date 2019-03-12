#include <iostream>
#include <vector>
using namespace std;

void dfs(int x);
vector<int> a[1001];
bool check[1001];
int cnt;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			dfs(i);
			cnt += 1;
		}		
	}
	cout << cnt;
	return 0;
}
void dfs(int x) {
	check[x] = true;
	for (int i = 0; i < a[x].size(); i++) {
		if (!check[a[x][i]]) {
			dfs(a[x][i]);
		}
	}
}