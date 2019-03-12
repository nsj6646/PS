#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	vector<string> v(5);
	int max = 0;
	for (int i = 0; i < 5; i++) {
		cin >> v[i];
		if (max < v[i].size()) {
			max = v[i].size();
		}
	}
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < 5; j++) {
			if (v[j].size() > i) {
				cout << v[j][i];
			}
		}
	}
	return 0;
}
//#include<cstdio>
//char s[5][16];
//int main() {
//	for (int i = 0; i < 5; i++) scanf("%s", s[i]);
//	for (int i = 0; i < 15; i++) for (int j = 0; j < 5; j++) if (s[j][i]) putchar(s[j][i]);
//	return 0;
//}