#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}
	if (n <= m) {
		cout << n;
		return 0;
	}

	long long left = 0, right = 2000000000LL * 10000LL;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long begin, end = m;

		for (int x : v) {
			end += mid / x;
		}
		begin = end;
		for (int x : v) {
			begin -= mid % x == 0 ? 1 : 0;
		}
		begin += 1;

		if (n < begin) {
			right = mid - 1;
		}
		else if (n > end) {
			left = mid + 1;
		}
		else {
			for (int i = 0; i < n; i++) {
				if (mid%v[i] == 0) {
					if (begin == n) {
						cout << i + 1;
						return 0;
					}
					begin += 1;
				}
			}
		}
	}
	return 0;
}

//#include <iostream>
//using namespace std;
//int a[10000];
//int p, n;
//int main() {
//	cin >> p >> n;
//	for (int i = 0; i<n; i++) {
//		cin >> a[i];
//	}
//	if (p <= n) {
//		printf("%d\n", p);
//		return 0;
//	}
//	long long left = 0;
//	long long right = 2000000000LL * 1000000LL;
//	while (left <= right) {
//		long long mid = (left + right) / 2;
//		long long begin, end;
//		begin = end = 0;
//		end = n;
//		for (int i = 0; i<n; i++) {
//			end += mid / a[i];
//		}
//		begin = end;
//		for (int i = 0; i<n; i++) {
//			if (mid % a[i] == 0) {
//				begin -= 1;
//			}
//		}
//		begin += 1;
//		if (p < begin) {
//			right = mid - 1;
//		}
//		else if (p > end) {
//			left = mid + 1;
//		}
//		else {
//			for (int i = 0; i<n; i++) {
//				if (mid % a[i] == 0) {
//					if (p == begin) {
//						printf("%d\n", i + 1);
//						return 0;
//					}
//					begin += 1;
//				}
//			}
//		}
//	}
//	return 0;
//}