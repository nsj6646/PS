#include <iostream>
#include <algorithm>

using namespace std;

bool buttons[10];

int possible(int n) {
	int cnt = 0;
	if (n == 0) {
		return buttons[0] ? 1000000 : 1;
	}
	while (n > 0) {
		if (buttons[n % 10]) {
			return 1000000;
		}
		cnt += 1;
		n /= 10;
	}
	return cnt;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		buttons[x] = true;	//����
	}

	int ans = 1000000;

	for (int i = 0; i <= 1000000; i++) {
		int cnt = possible(i);
		ans = min(ans, min(cnt + abs(n - i), abs(n - 100)));
		
	}
	cout << ans;

	return 0;
}

//#include <iostream>
//using namespace std;
//bool broken[10]; // ��ư�� ������ ������ true, �ƴϸ� false
//int possible(int c) {
//	if (c == 0) {
//		if (broken[0]) {
//			return 0;
//		}
//		else {
//			return 1;
//		}
//	}
//	int len = 0;
//	while (c > 0) {
//		if (broken[c % 10]) {
//			return 0;
//		}
//		len += 1;
//		c /= 10;
//	}
//	return len;
//}
//int main() {
//	int n;
//	cin >> n;
//	int m;
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		int x;
//		cin >> x;
//		broken[x] = true;
//	}
//	int ans = n - 100; // n >= 100
//	if (ans < 0) {
//		ans = -ans; // n < 100
//	}
//	for (int i = 0; i <= 1000000; i++) { // ���� ��ư���� �̵��ϴ� ä��
//		int c = i;
//		int len = possible(c); // ���̸� ���.
//		if (len > 0) {
//			int press = c - n; // +�� -�� �� �� ������ �ϴ��� ���
//			if (press < 0) {
//				press = -press; // +�� ������ ���
//			}
//			if (ans > len + press) {
//				ans = len + press;
//			}
//		}
//	}
//	printf("%d\n", ans);
//	return 0;
//}