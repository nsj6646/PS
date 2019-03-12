#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[500001];
vector<pair<int, int>> v(8001);
int main()
{
	int n;
	scanf("%d", &n);
	int sum = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		v[a[i]+4000].first -= 1;
		v[a[i]+4000].second = a[i];
	}
	printf("%.0f\n", (float)sum / n);
	sort(a, a + n);
	printf("%d\n", a[n/2]);
	sort(v.begin(), v.end());
	if (v[0].first == v[1].first) {
		printf("%d\n", v[1].second);
	}
	else {
		printf("%d\n", v[0].second);
	}
	printf("%d", a[n - 1] - a[0]);
	return 0;
}