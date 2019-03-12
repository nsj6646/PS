#include <iostream>
using namespace std;

int T;

int main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int a, b;
		cin >> a >> b;
		a %= 10;
		int ans = 1;
		switch (a)
		{
		case 0:
			cout << 10 << '\n';
			break;
		case 1:
		case 5:
		case 6:
			ans = a;
			cout << ans << '\n';
			break;
		case 2:
		case 3:
		case 7:
		case 8:
			b %= 4;
			if (b == 0) b = 4;
			for (int i = 0; i < b; i++) {
				ans *= a;
				ans %= 10;
			}
			cout << ans << '\n';
			break;
		case 4:
		case 9:
			b %= 2;
			if (b == 0) b = 2;	

			for (int i = 0; i < b; i++) {
				ans *= a;
				ans %= 10;
			}
			cout << ans << '\n';
			break;
		}
	}
	return 0;
}