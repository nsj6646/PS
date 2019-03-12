#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> e(n - 1);	//도로
	vector<int> v(n);	//도시
	
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &e[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	long long min = v[0];
	long long ans = v[0] * e[0];
	for (int i = 1; i < n - 1; i++) {
		if (v[i] < min) {
			min = v[i];
		}
		ans += min * e[i];
	}
	printf("%lld", ans);
	return 0;
}
//
//#include <cstdio>
//
//long long n, a[100001], b[100001], ans;
//
//int main()
//{
//	scanf("%lld", &n);
//	for (int i = 1; i < n; i++) {
//		scanf("%lld", &a[i]);
//	}
//
//	for (int i = 0; i < n; i++) {
//		scanf("%lld", &b[i]);
//	}
//	for (int i = 0; i < n;) {
//		int sum = 0, chk = 0;
//		for (int j = i + 1; j < n; j++) {
//			sum += a[j];
//			if (b[i] >= b[j]) {
//				chk = 1;
//				ans += sum * b[i];
//				i = j;
//				break;
//			}
//		}
//		if (chk == 0) {
//			ans += sum * b[i];
//			break;
//		}
//	}
//	printf("%lld", ans);
//	return 0;
//}