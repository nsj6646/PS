//http://jason9319.tistory.com/290?category=666243 ÂüÁ¶.
#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 0x7fffffff
using namespace std;
int a[3];
int dp[61][61][61];

int attack(int x, int y, int z) {
	if (x == 0 && y == 0 && z == 0) {
		return 0;
	}
	int &ret = dp[x][y][z];
	if (ret != -1) {
		return ret;
	}
	ret = INF;
	ret = min(ret, attack(max(0, x - 9), max(0, y - 3), max(0, z - 1)) + 1);
	ret = min(ret, attack(max(0, x - 9), max(0, y - 1), max(0, z - 3)) + 1);
	ret = min(ret, attack(max(0, x - 3), max(0, y - 9), max(0, z - 1)) + 1);
	ret = min(ret, attack(max(0, x - 1), max(0, y - 9), max(0, z - 3)) + 1);
	ret = min(ret, attack(max(0, x - 3), max(0, y - 1), max(0, z - 9)) + 1);
	ret = min(ret, attack(max(0, x - 1), max(0, y - 3), max(0, z - 9)) + 1);
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << attack(a[0], a[1], a[2]);
	return 0;
}
