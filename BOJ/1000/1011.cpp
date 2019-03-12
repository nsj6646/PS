#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int x, y;
		int k = 1;
		scanf("%d %d", &x, &y);
		int ans = 0;
		while (x <= y) {
			x += k;
			ans += 1;
			if (x >= y) {
				break;
			}
			else {
				y -= k;
				ans += 1;
				if (x >= y) {
					break;
				}
			}
			k += 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}