#include <iostream>
#include <vector>
using namespace std;
long long f[21] = { 1 };
bool nums[21];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < 21; i++) {
		f[i + 1] = (i + 1)*f[i];
	}

	if (m == 1) {
		long long k;
		cin >> k;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 1; j <= n; j++) {
				if (nums[j]) {
					continue;
				}
				if (k > f[i]) {
					k -= f[i];
				}
				else {
					v.push_back(j);
					nums[j] = true;
					break;
				}
			}
		}
		for (int x : v) {
			cout << x << ' ';
		}
	}
	else {
		v.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		long long k = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < v[i]; j++) {
				if (nums[j]) {
					continue;
				}
				k += f[n - 1 - i];
			}
			nums[v[i]] = true;
		}
		cout << k;
	}

	return 0;
}

//#include <iostream>
//#include <vector>
//using namespace std;
//long long f[21] = { 1 };
//bool c[21];
//int main() {
//	for (int i = 1; i <= 20; i++) {
//		f[i] = f[i - 1] * i;
//	}
//	int n;
//	cin >> n;
//	int what;
//	cin >> what;
//	if (what == 2) {
//		vector<int> a(n);
//		for (int i = 0; i<n; i++) {
//			cin >> a[i];
//		}
//		long long ans = 0;
//		for (int i = 0; i<n; i++) {
//			for (int j = 1; j<a[i]; j++) {
//				if (c[j] == false) {
//					ans += f[n - i - 1];
//				}
//			}
//			c[a[i]] = true;
//		}
//		cout << ans + 1 << '\n';
//	}
//	else if (what == 1) {
//		long long k;
//		cin >> k;
//		vector<int> a(n);
//		for (int i = 0; i<n; i++) {
//			for (int j = 1; j <= n; j++) {
//				if (c[j] == true) continue;
//				if (f[n - i - 1] < k) {
//					k -= f[n - i - 1];
//				}
//				else {
//					a[i] = j;
//					c[j] = true;
//					break;
//				}
//			}
//		}
//		for (int i = 0; i<n; i++) {
//			cout << a[i] << ' ';
//		}
//		cout << '\n';
//	}
//	return 0;
//}