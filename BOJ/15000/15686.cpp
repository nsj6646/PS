#include <cstdio>
#include <vector>
#include <algorithm>
#define N 51
#define INFI 0x7fffffff
#define ABS(x) ((x)>=0?(x):-(x))
using namespace std;
typedef pair<int, int> point;

int a[N][N];
int check[N][N];
int n, m;
vector<point> v;
vector<point> chckn;
vector<point> house;

int ans = INFI;
int taxi_dist(const point &v, const point &w) {
	return ABS(v.first - w.first) + ABS(v.second - w.second);
}
int dist() {
	int c_dist = 0;
	
	for (auto &hp : house) {
		int m_dist = INFI;
		for (auto &cp : chckn) {
			m_dist = min(m_dist, taxi_dist(hp, cp));
		}
		c_dist += m_dist;
	}
	return c_dist;
}
void dfs(int idx, int cnt) {
	if (cnt == m) {
		int t = dist();
		ans = min(ans, t);
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		chckn.push_back(v[i]);
		int x = v[i].first;
		int y = v[i].second;
		check[x][y] = 2;
		dfs(i + 1, cnt + 1);
		check[x][y] = 0;
		chckn.pop_back();
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 2) {
				v.push_back({ i,j });
			}
			else if(a[i][j]==1){
				check[i][j] = 1;
				house.push_back({ i,j });
			}
		}
	}

	dfs(0, 0);
	printf("%d", ans);
	return 0;
}	