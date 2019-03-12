#include <cstdio>
#include <vector>
using namespace std;
int a[201][201];
int n, m;

int ans;
void solve(vector<int> &v, int i, int cnt) {
	if (i > n) {
		if (cnt == 3) {
			ans += 1;
		}
		return;
	}
	
	if (cnt == 3) {
		ans += 1;
		return;
	}
	
	if (v.empty()) {
		/*비었으면 그냥 넣기or안넣기*/
		v.push_back(i);
		solve(v, i + 1, cnt+1);
		v.pop_back();
		solve(v, i + 1, cnt);
	}
	else {
		/*검사하고 넣기or안넣기*/
		bool ispossible = true;
		for (int x : v) {
			if (a[i][x] == 1) {
				ispossible = false;
			}
		}
		if (ispossible) {
			v.push_back(i);
			solve(v, i + 1, cnt + 1);
			v.pop_back();
		}
		solve(v, i + 1, cnt);
	}

}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	vector<int> v;
	solve(v,1,0);
	printf("%d", ans);
	return 0;
}