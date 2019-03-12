#include <iostream>
using namespace std;

int n, s;
int a[20];
int ans;
void dfs(int idx, int sum) {
	if (idx == n) {
		return;
	}
	if (idx!=-1&&sum == s) {
		ans += 1;
	}
	for (int i = idx+1; i < n; i++) {
		dfs(i, sum+a[i]);
	}
}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dfs(-1, 0);
	cout << ans;
	return 0;
}
//#include <iostream>
//#include <bitset>
//using namespace std;
//
//int a[20];
//int main()
//{
//	int n, s;
//	cin >> n >> s;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//
//	int ans = 0;
//
//	for (int i = 1; i < (1 << n); i++) {
//		int sum = 0;
//		for (int k = 0; k < n; k++) {
//			if (i&(1 << k)) {
////				cout << "i : " << bitset<5>(i) << " k: " << bitset<5>(1<<k) << '\n';
//				sum += a[k];
//			}
//		}
//		if (sum == s) {
//			ans += 1;
//		}
//	}
//	cout << ans;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//int a[20];
//int ans;
//int n, s;
//
//void sumset(int i, int sum) {
//	if (i == n) {
//		if (sum == s) {
//			ans += 1;
//		}
//		return;
//	}
//	sumset(i + 1, sum + a[i]);
//	sumset(i + 1, sum);
//
//
//}
//int main()
//{
//
//	cin >> n >> s;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//
//	sumset(0, 0);
//	if (s == 0) {
//		ans -= 1;
//	}
//	cout << ans;
//	return 0;
//}