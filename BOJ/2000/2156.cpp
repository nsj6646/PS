#include <cstdio>
#include <algorithm>
using namespace std;

int d[10001];
int w[10001];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	d[1] = w[1];
	d[2] = w[1] + w[2];
	for (int i = 3; i <= n; i++) {
		d[i] = max(d[i - 3] + w[i - 1] + w[i], max(d[i - 2] + w[i], d[i - 1]));
	}
	printf("%d", d[n]);
	return 0;
}