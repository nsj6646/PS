#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int ans = 0;
	int len = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] == 1) {
			len += 1;
		}
		else {
			ans = max(ans, len);
			len = 1;
		}
	}
	ans = max(ans, len);
	cout << ans;

	return 0;
}