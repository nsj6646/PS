#include <iostream>
using namespace std;

int cnt;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 5; i++) {
		int c;
		cin >> c;
		if (c == n) {
			cnt += 1;
		}
	}
	cout << cnt;
	return 0;
}