#include <cstdio>
#include <cstring>
int fibonacci(int n);
int d[41];
int c[2][41];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		fibonacci(n);
		printf("%d %d\n", c[0][n], c[1][n]);
	}
	return 0;
}
int fibonacci(int n) {
	if (n <= 1) {
		c[n][n] = 1;
		return n;
	}
	else {
		if (d[n] > 0) {
			if (c[0][n] == 0) {
				c[0][n] += c[0][n];
				c[1][n] += c[1][n];
			}
			return d[n];
		}
		else {
			d[n] = fibonacci(n - 1) + fibonacci(n - 2);
			if (c[0][n] == 0) {
				c[0][n] = c[0][n - 1] + c[0][n - 2];
				c[1][n] = c[1][n - 1] + c[1][n - 2];
			}
			
			return d[n];
		}
	}
}