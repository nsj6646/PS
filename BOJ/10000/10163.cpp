#include <cstdio>

int a[101][101];
int cp[101];
int main()
{
	int n;
	scanf("%d", &n);
	int x, y, w, h;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d %d", &x, &y, &w, &h);
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				a[y + j][x + k] = i;
			}
		}
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			cp[a[i][j]] += 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", cp[i]);
	}
	return 0;
}