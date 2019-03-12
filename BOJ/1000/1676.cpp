#include <iostream>
using namespace std;

int main()
{
	int n;
	int ans = 0;
	cin >> n;
	ans = n / 5 + n / 25 + n / 125;
	cout << ans;
	return 0;
}
/*
#include <iostream>
using namespace std;
int main() {
	int ans = 0;
	int n;
	cin >> n;
	for (int i = 5; i <= n; i *= 5) {
		ans += n / i;
	}
	cout << ans << '\n';
	return 0;
}
*/