#define MAX(X,Y)	(X)>(Y)?(X):(Y)
#include <cstdio>

int a[1001];
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	int ans = 0;
	int low = 0, high = 0;
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			low = high = a[i];
			continue;
		}
		if (a[i] > high) {
			high = a[i];
		}
		else {
			ans = MAX(ans, high - low);
			low = high = a[i];
		}
	}
	ans = MAX(ans, high - low);
	printf("%d", ans);
	return 0;
}