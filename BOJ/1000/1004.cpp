#include <cstdio>

int x1, y1, x2, y2;
int n;

bool isinside(int x, int y, int r, int p) {
	return ((p - 1) ? ((x - x2)*(x - x2) + (y - y2)*(y - y2)<(r*r)) : ((x - x1)*(x - x1) + (y - y1)*(y - y1)<(r*r)));
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int ans = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int x, y, r;
			scanf("%d %d %d", &x, &y, &r);
			ans += isinside(x, y, r, 1) ^ isinside(x, y, r, 2);
		}
		printf("%d\n", ans);
	}
	return 0;
}