#include <iostream>
#include <cmath>
using namespace std;

typedef struct {
	int x, y, r;
}point;
inline double dist_r(const point &p1, const point &p2) {
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}
int main()
{
	int T;
	cin >> T;
	point p[2];
	for (int tc = 1; tc <= T; tc++) {
		int ans = 2;
		for (int i = 0; i < 2; i++) {
			cin >> p[i].x >> p[i].y >> p[i].r;
		}
		double dist = dist_r(p[0], p[1]);
		point &b = p[0].r > p[1].r ? p[0] : p[1];
		point &s = p[0].r > p[1].r ? p[1] : p[0];
		if (b.x == s.x&&b.y == s.y&&b.r == s.r) {
			ans = -1;
		}
		else if (dist == (b.r + s.r) || dist == (b.r - s.r)) {
			ans = 1;
		}
		else if (dist > (b.r + s.r)|| dist < (b.r - s.r)) {
			ans = 0;
		}
		cout << ans << '\n';
	}
	return 0;
}