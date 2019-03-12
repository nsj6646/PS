#include <cstdio>
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n - 1; j++) {
			putchar(' ');
		}
		for (int j = 1; j <= 2*i-1; j++) {
			putchar('*');
		}
		putchar('\n');
	}
	return 0;
}