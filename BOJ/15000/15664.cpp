#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
vector<int> ans;
int a[10001];
int cnt[10001];
set<vector<int>> visited;
int n, m;
void solve(int l) {
	if (l == m) {
		if (visited.count(ans) == 0) {
			visited.insert(ans);
			for (int x : ans) {
				printf("%d ", x);
			}
			printf("\n");
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		int &x = a[i];
		if (cnt[x]>0&&(ans.empty()||x>=ans.back())) {
			cnt[x] -= 1;
			ans.push_back(x);
			solve(l + 1);
			ans.pop_back();
			cnt[x] += 1;
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]] += 1;
	}
	sort(a, a + n);
	solve(0);
	return 0;
}