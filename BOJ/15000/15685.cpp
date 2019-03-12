#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> point;
int n;
int a[101][101];
/*
0: x좌표가 증가하는 방향 (→)
1: y좌표가 감소하는 방향 (↑)
2: x좌표가 감소하는 방향 (←)
3: y좌표가 증가하는 방향 (↓)

0->3
1->0
2->1
3->2
-----------
0->1
1->2
2->3
3->0
------------
0
0 1
0 1 2 1
0 1 2 1 2 3 2 1
*/
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

void solve(vector<int> &v, int g, int cnt) {
	while (cnt <= g) {
		int size = v.size();
		for (int i = size - 1; i >= 0; i--) {
			switch (v[i]) {
			case 0: v.push_back(1); break;
			case 1: v.push_back(2); break;
			case 2: v.push_back(3); break;
			case 3: v.push_back(0); break;
			}
		}
		cnt += 1;
	}
}
void draw(vector<int> &v,point sp) {
	int x = sp.first;
	int y = sp.second;
	a[y][x] = 1;
	for (int i = 0; i < v.size(); i++) {
		x += dx[v[i]];
		y += dy[v[i]];
		a[y][x] = 1;
	}
}
bool issquare(int x,int y) {
	if (a[y][x] == 1 && a[y][x + 1] == 1 && a[y + 1][x] == 1 && a[y + 1][x + 1] == 1) {
		return true;
	}
	else {
		return false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		vector<int> v;
		v.push_back(d);
		solve(v, g, 1);
		draw(v, { x,y });
	}
	for (int i = 0; i <100; i++) {
		for (int j = 0; j < 100; j++) {
			if (issquare(j, i)) {
				ans += 1;
			}
		}
	}
	cout << ans;
	return 0;
}