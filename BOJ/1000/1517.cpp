#include <iostream>
using namespace std;

int a[500000];
int b[500000];

long long merge(int start, int end) {
	if (start == end) {
		return 0;
	}
	int mid = (start + end) / 2;
	long long ans = merge(start, mid) + merge(mid + 1, end);
	int i = start;
	int j = mid + 1;
	int k = 0;

	while (i <= mid || j <= end) {
		if (i <= mid && (j > end || a[i] <= a[j])) {
			b[k++] = a[i++];
		}
		else {
			ans += (long long)mid + 1 - i;
			b[k++] = a[j++];

		}
	}
	for (int i = start; i <= end; i++) {
		a[i] = b[i - start];
	}
	return ans;

}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << merge(0, n - 1);

	return 0;
}
//
//#include <cstdio>
//int a[500000];
//int b[500000];
//long long solve(int start, int end) {
//	if (start == end) {
//		return 0;
//	}
//	int mid = (start + end) / 2;
//	long long ans = solve(start, mid) + solve(mid + 1, end);
//	int i = start;
//	int j = mid + 1;
//	int k = 0;
//	while (i <= mid || j <= end) {
//		if (i <= mid && (j > end || a[i] <= a[j])) {
//			b[k++] = a[i++];
//		}
//		else {
//			ans += (long long)(mid - i + 1);
//			b[k++] = a[j++];
//		}
//	}
//	for (int i = start; i <= end; i++) {
//		a[i] = b[i - start];
//	}
//	return ans;
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i<n; i++)
//		scanf("%d", &a[i]);
//	long long ans = solve(0, n - 1);
//	printf("%lld\n", ans);
//	return 0;
//}