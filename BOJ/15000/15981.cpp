#include <cstdio>

int n, k;

int main()
{
	scanf("%d", &n);

	int x = 1;
	for (k = 0; x < n; ++k) {
		x <<= 1;
	}
	printf("%d\n", k);
	for (int l = 1; l <= k; ++l) {
		printf("%d ", ((n+(1<<(l-1))) / (1 << l))*(1<<(l-1)));
		for (int i = 1; i <= n; i += (1<<l)) {
			for (int j = 0; j < ((1<<(l-1)))&&(i+(1<<(l-1))<=n); ++j) {
				printf("%d ", j + i);
			}
		}
		printf("\n");
	}
	return 0;
}