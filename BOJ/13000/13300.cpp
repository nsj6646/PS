#include <iostream>
using namespace std;

int r[2][6];
int main()
{
	int n, k;
	cin >> n >> k;
	int s, y;
	for (int i = 0; i < n; i++) {
		cin >> s >> y;
		r[s][y - 1] += 1;
	}
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			if (r[i][j] != 0) {
				ans += 1+ (r[i][j]-1)/k;
			}
		}
	}
	cout << ans;

	return 0;
}
/*
#include <cstdio>

int n, k, s, y, a[7][2], ans;
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s, &y);
		a[y][s]++;
	}
	for (int i = 1; i <= 6; i++) {
		for (int j = 0; j < 2; j++) {
			if (a[i][j] % k != 0)
				ans++;
			ans += a[i][j] / k;
		}
	}
	printf("%d", ans);
	return 0;
}
*/