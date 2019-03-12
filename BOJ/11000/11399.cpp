#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	//int ans = 0;
	//for (int i = 0; i < n; i++) {
	//	int sum = 0;
	//	for (int j = 0; j < i; j++) {
	//		sum += v[j];
	//	}
	//	ans += v[i] + sum;
	//}
	int sum = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		ans += sum;
	}
	printf("%d", ans);

	return 0;
}