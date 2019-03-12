#include <iostream>
using namespace std;

int k;
void move(int from, int to, int n) {
	if (n == 0) {
		return;
	}
	move(from, 6-from-to, n - 1);
	cout << from << ' ' << to << '\n';
	move(6 - from - to, to, n - 1);
}
int main()
{
	int n;
	cin >> n;

	cout << (1 << n) - 1 << '\n';
	move(1, 3, n);

	return 0;
}

//#include <cstdio>
//void solve(int n, int x, int y) {
//	if (n == 0) return;
//	solve(n - 1, x, 6 - x - y);
//	printf("%d %d\n", x, y);
//	solve(n - 1, 6 - x - y, y);
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	printf("%d\n", (1 << n) - 1);
//	solve(n, 1, 3);
//	return 0;
//}