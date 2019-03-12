//#include <iostream>
//using namespace std;
//char str[101];
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	int count = 1;
//	
//	cin >> str;
//	for (auto x : str) {
//		if (x == ',') {
//			count++;
//		}
//	}
//	cout << count;
//	return 0;
//}
#include <iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int cnt = 0;
	while (getline(cin, s, ',')) {
		cnt += 1;
	}
	cout << cnt;
	return 0;
}