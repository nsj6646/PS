#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str)) {
		int lower = 0;
		int upper = 0;
		int number = 0;
		int space = 0;
		for (char c : str) {
			if (c >= 'a'&&c <= 'z') {
				lower += 1;
			}
			else if (c >= 'A'&&c <= 'Z') {
				upper += 1;
			}
			else if (c >= '0'&&c <= '9') {
				number += 1;
			}
			else if (c == ' ') {
				space += 1;
			}

		}
		cout << lower << ' ' << upper << ' ' << number << ' ' << space << '\n';
	}

	return 0;
}