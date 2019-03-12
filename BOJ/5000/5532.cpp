#include <cstdio>

int main()
{
	int l, a, b, c, d;
	scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
	while (a > 0 || b > 0) {
		l -= 1;
		a -= c;
		b -= d;
	}
	printf("%d", l);
	return 0;
}