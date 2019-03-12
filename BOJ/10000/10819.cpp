#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int max = 0;
	do {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		if (sum >= max)max = sum;
	} while (next_permutation(v.begin(), v.end()));
	cout << max;
	return 0;
}
//#include <algorithm>
//#include <iostream>
//#include <vector>
//using namespace std;
//int calculate(vector<int> &a) {
//	int sum = 0;
//	for (int i = 1; i<a.size(); i++) {
//		sum += abs(a[i] - a[i - 1]);
//	}
//	return sum;
//}
//int main() {
//	int n;
//	cin >> n;
//
//	vector<int> a(n);
//	for (int i = 0; i<n; i++) {
//		cin >> a[i];
//	}
//
//	sort(a.begin(), a.end());
//
//	int ans = 0;
//
//	do {
//		int temp = calculate(a);
//		ans = max(ans, temp);
//	} while (next_permutation(a.begin(), a.end()));
//
//	cout << ans << '\n';
//	return 0;
//}