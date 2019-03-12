#include <cstdio>
#include <vector>
using namespace std;
void solve(int n, int m, int depth, vector<int> &v) {
	if (depth == m) {
		for (int x : v) {
			printf("%d ", x);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (v.empty() || v.back() <= i) {
			v.push_back(i);
			solve(n, m, depth + 1, v);
			v.pop_back();
		}
	}
}
int main()
{
	int n, m;
	vector<int> v;
	scanf("%d %d", &n, &m);
	solve(n, m, 0, v);
	return 0;
}