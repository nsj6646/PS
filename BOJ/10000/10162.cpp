#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int a, b, c;
	if (t % 10 != 0) {
		cout << -1;
		return 0;
	}
	a = t / 300;
	b = (t % 300) / 60;
	c = (t % 60) / 10;

	cout << a << ' ' << b << ' ' << c;
	return 0;
}