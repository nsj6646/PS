#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	double a[501] = { 0.0 };
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%lf", &a[i]);
	}
	double ans = 100000000.0;

	for (; k <= n; k++) {
		double s[501] = { 0 };
		double m[501] = { 0 };
		double v = 0;
		double d = 0;
		for (int i = 1; i <= n - k + 1; i++) {
			if (i == 1) {
				for (int j = 1; j <= k; j++) {
					s[i] += a[j];
				}
			}
			else {
				s[i] = s[i - 1] - a[i - 1] + a[i + k - 1];
			}
			m[i] = s[i] / k;
		}

		for (int i = 1; i <= n - k + 1; i++) {
			v = 0;
			for (int j = i; j < i + k; j++) {
				v += (a[j] - m[i])*(a[j] - m[i]);
			}
			v /= k;
			d = abs(sqrt(v) - 0.000000000005);
			ans = min(ans, d);
		}
	}

	printf("%.11lf", ans);

	return 0;
}