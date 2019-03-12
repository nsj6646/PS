#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int num[26];
int main()
{
	string str;
	cin >> str;

	for (char x : str) {
		num[x - 'a'] = count(str.begin(), str.end(), x);
	}
	for (int x : num) {
		cout << x << ' ';
	}
	return 0;
}