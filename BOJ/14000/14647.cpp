#define MAX(X,Y)	(X)>(Y)?(X):(Y)
#include <cstdio>

char a[500][500][10];
int n, m;
int main()
{
	int total = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%s", a[i][j]);
			for (int k = 0; a[i][j][k]; ++k) {
				if (a[i][j][k] == '9') {
					total += 1;
				}
			}
		}

	}
	int max = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < m; ++j) {
			for (int k = 0; a[i][j][k]; ++k) {
				if (a[i][j][k] == '9') {
					cnt += 1;
				}
			}
		}
		max = MAX(max, cnt);
	}
	for (int i = 0; i < m; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; a[j][i][k]; ++k) {
				if (a[j][i][k] == '9') {
					cnt += 1;
				}
			}
		}
		max = MAX(max, cnt);
	}
	printf("%d", total - max);
	return 0;
}