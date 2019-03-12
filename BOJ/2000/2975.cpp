#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, c;
	char b;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b == 'W'&&c == 0) {
			break;
		}
		if (b == 'W') {
			int res = a - c;
			if (res < -200) {
				cout << "Not allowed\n";
			}
			else {
				cout << res << '\n';
			}
		}
		else {
			cout << a + c << '\n';
		}
	}
	return 0;
}