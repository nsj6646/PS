#include <iostream>
#include <string>
using namespace std;

int main()
{
	string n;
	int b;
	cin >> n >> b;
	int ans = 0;
	for (int i = 0; i < n.size(); i++) {
		if ('0' <= n[i] && n[i] <= '9') {
			ans = ans * b + (n[i] - '0');
		}
		else {
			ans = ans * b + (n[i] - 'A' + 10);
		}
	}
	cout << ans;
	return 0;
}
//#include <iostream>
//#include <cmath>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string str;
//	int b;
//	cin >> str >> b;
//	int n = str.size();
//	int ans = 0;
//	for (int i = n - 1; i >= 0; i--) {
//		if (str[i] >= 'A'&&str[i] <= 'Z') {
//			ans += (str[i] - 'A' + 10)*(int)pow((double)b, (double)((n - 1) - i));
//		}
//		else {
//			ans += (str[i] - '0')*(int)pow((double)b, (double)((n - 1) - i));
//		}
//	}
//	cout << ans;
//	return 0;
//}