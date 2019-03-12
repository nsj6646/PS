#include <iostream>
using namespace std;

bool paper[100][100];
int main()
{
	int n;
	cin >> n;
	for (int p = 0; p < n; p++) {
		int x, y;
		cin >> x >> y;
		for (int i = y; i < y + 10; i++) {
			for (int j = x; j < x + 10; j++) {
				paper[i][j] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paper[i][j]) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}