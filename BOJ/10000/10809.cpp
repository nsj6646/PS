#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	
	for (char c = 'a'; c <= 'z'; c++) {
		auto it = find(str.begin(), str.end(), c);
		if (it == str.end()) {
			cout << -1 << ' ';
		}
		else {
			cout << it - str.begin() << ' ';
		}
	}
	return 0;
}