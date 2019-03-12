#include <iostream>
using namespace std;

int main()
{
	int p;
	cin >> p;
	int ch = 1000 - p;
	int ans = 0;

	ans += ch / 500;
	ch %= 500;
	ans += ch / 100;
	ch %= 100;
	ans += ch / 50;
	ch %= 50;
	ans += ch / 10;
	ch %= 10;
	ans += ch / 5;
	ch %= 5;
	ans += ch / 1;

	cout << ans;


	return 0;
}