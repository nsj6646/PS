#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n - 1; i++) {
		if (i <= n) {
			for (int j = 1; j <= i; j++) {
				putchar('*');
			}
			for (int j = i; j < n; j++) {
				putchar(' ');
			}
			for (int j = i; j < n; j++) {
				putchar(' ');
			}
			for (int j = 1; j <= i; j++) {
				putchar('*');
			}			
		}
		else {
			for (int j = 1; j <= 2 * n - i; j++) {
				putchar('*');
			}
			for (int j = n; j < i; j++) {
				putchar(' ');
			}
			for (int j = n; j < i; j++) {
				putchar(' ');
			}
			for (int j = 1; j <= 2 * n - i; j++) {
				putchar('*');
			}
		}
		putchar('\n');
	}
	return 0;
}