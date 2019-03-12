#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int cnt = 0;
	string str;
	while (cin >> str) {
		cnt += 1;
	}
	cout << cnt;
	return 0;
}