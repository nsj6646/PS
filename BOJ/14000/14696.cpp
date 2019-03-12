#include <iostream>
#include <cstring>
using namespace std;
//별, 동그라미, 네모, 세모를 각각 숫자 4, 3, 2, 1로 표현한다

int a[5];
int b[5];
char ans[1001];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	for (int tc = 1; tc <= n; tc++) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));

		int m, x, y;
		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> x;
			a[x]++;
		}
		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> y;
			b[y]++;
		}
		int  totala = 1030301 * a[4] + 10201 * a[3] + 101 * a[2] + a[1];
		int totalb = 1030301 * b[4] + 10201 * b[3] + 101 * b[2] + b[1];

		if (totala > totalb) {
			ans[tc] = 'A';
		}
		else if (totala < totalb) {
			ans[tc] = 'B';
		}
		else {
			ans[tc] = 'D';
		}
	}
	for (int tc = 1; tc <= n; tc++) {
		cout << ans[tc] << '\n';
	}
	return 0;
}