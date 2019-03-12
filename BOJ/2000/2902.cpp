#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	stringstream sin(str);
	string kmp;
	while (getline(sin,kmp , '-')) {
		cout << kmp[0];
	}
	return 0;
}