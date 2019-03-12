#include <cstdio>

int gcd(int x, int y) {
	return y ? gcd(y, x%y) : x;
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int m, n, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);
		int l = lcm(m, n);
		int ans = -1;
		for (int i = 0; i < l / m; i++) {
			if ((i*m + x - y) % n == 0) {
				ans = i * m + x;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
#include<cstdio>

int t;
int m, n, x, y;

int gcd(int x, int y) {
	if (x % y == 0) return y;
	else return(gcd(y, x%y));
}

int main() {
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d %d %d", &m, &n, &x, &y);

		int mn = m * n / gcd(m, n);

		while (x != y && x <= mn) {
			if (x < y) x += m;
			else y += n;
		}
		if (x != y) printf("-1\n");
		else printf("%d\n", x);
	}
}
*/