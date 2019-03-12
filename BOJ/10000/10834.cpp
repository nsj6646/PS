#include <cstdio>

int main()
{
	int m;
	int type = 0;
	int r = 1;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		r = r * y / x;
		type = (type + z) % 2;
	}

	printf("%d %d", type, r);
	return 0;
}