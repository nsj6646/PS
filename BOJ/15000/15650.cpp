#include <cstdio>
#include <vector>
using namespace std;
int visited[9];

void solve(int n, int m,int depth, vector<int> &v) {
	if (depth == m) {
		for (int x : v) {
			printf("%d ", x);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0&&(v.empty()||v.back()<i)) {
			visited[i] = 1;
			v.push_back(i);
			solve(n, m, depth + 1,v);
			v.pop_back();
			visited[i] = 0;
		}
	}
}
int main()
{
	int n, m;
	vector<int> v;
	scanf("%d %d", &n, &m);
	solve(n, m, 0,v);
	return 0;
}