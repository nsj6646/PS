#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int ans;
	if (n == 1) {
		ans = 1;
	}
	else if (n == 2) {
		ans = min(4, (m + 1) / 2);
	}
	else if (n >= 3) {
		if (m < 7) {
			ans = min(4, m);
		}
		else {
			ans = m - 2;
		}
	}
	cout << ans;

	return 0;
}