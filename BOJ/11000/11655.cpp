#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A'&&str[i] <= 'Z') {
			str[i] = 'A' + (str[i] - 'A' + 13) % 26;
		}
		else if (str[i] >= 'a'&&str[i] <= 'z') {
			str[i] = 'a' + (str[i] - 'a' + 13) % 26;
		}
	}
	cout << str;
	return 0;
}