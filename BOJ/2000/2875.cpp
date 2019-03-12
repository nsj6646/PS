#include <iostream>
using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int a, b;
	while (k>0) {
		a = n - 2 * m;
		b = m - n / 2;
		if (a > b) {
			k -= a;
			n -= a;
		}
		else if (a<b){
			k -= b;
			m -= b;
		}
		else {
			n--;
			k--;
		}
	}

	cout << n / 2;
	return 0;
}
#include <iostream>
using namespace std;
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	int ans = 0;
	while (m >= 2 && n >= 1 && m + n >= k + 3) {
		ans += 1;
		m -= 2;
		n -= 1;
	}
	cout << ans << '\n';
	return 0;
}