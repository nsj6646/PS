#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a, s;
		cin >> a >> s;
		ans += s % a;
	}
	cout << ans;
	return 0;
}