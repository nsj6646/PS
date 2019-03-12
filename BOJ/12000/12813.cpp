#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	bitset<100000> A(s1), B(s2);
	cout << (A&B) << '\n';
	cout << (A|B) << '\n';
	cout << (A^B) << '\n';
	cout << (~A) << '\n';
	cout << (~B) << '\n';
	return 0;
}