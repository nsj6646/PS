#include <cstdio>
#include <algorithm>
using namespace std;

double x[101], y[101];
int main()
{
	scanf("%lf %lf",&x[0], &y[0]);
	double ans = x[0] / y[0] * 1000;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf %lf", &x[i], &y[i]);
		ans = min(ans,x[i] / y[i] * 1000);
	}
	printf("%.2lf", ans);
	return 0;
}
