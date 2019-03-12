#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int d[3][100001];
int a[2][100001];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 3; i++) {
			memset(d[i], 0, sizeof(int)*n);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[0][i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[1][i]);
		}
		d[0][0] = d[0][1] = d[0][2] = 0;
		for (int i = 1; i <= n; i++) {
			d[0][i] = max(d[0][i - 1], max(d[1][i - 1], d[2][i - 1]));
			d[1][i] = max(d[0][i - 1], d[2][i - 1]) + a[0][i];
			d[2][i] = max(d[0][i - 1], d[1][i - 1]) + a[1][i];
		}
		printf("%d\n", max(d[0][n], max(d[1][n], d[2][n])));

	}
	return 0;
}