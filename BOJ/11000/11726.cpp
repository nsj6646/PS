#include <cstdio>

int d[1001];
int tile(int n);
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", tile(n));
	return 0;
}
int tile(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		if (d[n] < 1) {
			d[n] = (tile(n - 1) + tile(n - 2)) % 10007;
			return d[n];
		}
		else {
			return d[n];
		}
	}
}