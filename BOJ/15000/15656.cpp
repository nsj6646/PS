#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ans;
int a[10001];
int n, m;
void solve(int l) {
	if (l == m) {
		for (int x : ans) {
			printf("%d ", x);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		int &x = a[i];
		ans.push_back(x);
		solve(l + 1);
		ans.pop_back();
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	solve(0);
	return 0;
}