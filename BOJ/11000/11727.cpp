#include <cstdio>

int d[1001];
int tile2(int n);
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", tile2(n));
	return 0;
}
int tile2(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		if (d[n] < 1) {
			d[n] = (tile2(n - 1) + 2*tile2(n - 2)) % 10007;
			return d[n];
		}
		else {
			return d[n];
		}
	}
}