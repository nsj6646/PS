#include <cstdio>

typedef struct point {
	int r, c;
}point;
point pos[101];
int main()
{
	int m = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int x;
			scanf("%d", &x);
			if (x > m) {
				m = x;
				pos[m].r = i;
				pos[m].c = j;
			}
		}
	}
	printf("%d\n", m);
	printf("%d %d\n", pos[m].r, pos[m].c);

	return 0;
}