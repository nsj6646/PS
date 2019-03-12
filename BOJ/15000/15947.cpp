#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string str[14] = {
		"baby","sukhwan","tururu","turu",
		"very","cute","tururu","turu",
		"in","bed","tururu","turu",
		"baby","sukhwan"
	};

	int k = (n-1) / 14;
	int k1 = 2 + k;
	int k2 = 1 + k;

	if (k1 >= 5) {
		str[2] = "tu+ru*" + to_string(k1);
		str[6] = "tu+ru*" + to_string(k1);
		str[10] = "tu+ru*" + to_string(k1);
	}
	else {
		for (int i = 0; i < k; i++) {
			str[2] += "ru";
			str[6] += "ru";
			str[10] += "ru";
		}
	}
	if (k2 >= 5) {
		str[3] = "tu+ru*" + to_string(k2);
		str[7] = "tu+ru*" + to_string(k2);
		str[11] = "tu+ru*" + to_string(k2);
	}
	else {
		for (int i = 0; i < k; i++) {
			str[3] += "ru";
			str[7] += "ru";
			str[11] += "ru";
		}
	}
	int idx = ((n % 14) ? n % 14 : 14)-1;
	cout << str[idx];
	//cout << k << ' ' << idx << '\n';
	
	return 0;
}