#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	int n, b;
	scanf("%d %d", &n, &b);
	stack<int> s;
	while (n / b != 0) {
		s.push(n % b);
		n /= b;
	}
	s.push(n);
	while (!s.empty()) {
		int num = s.top();
		s.pop();
		if (num >= 10) {
			printf("%c", num - 10 + 'a');
		}
		else {
			printf("%d", num);
		}
	}
	return 0;
}
//#include <algorithm>
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int n, b;
//	cin >> n >> b;
//	string ans = "";
//	while (n > 0) {
//		int r = n % b;
//		if (r < 10) {
//			ans += (char)(r + '0');
//		}
//		else {
//			ans += (char)(r - 10 + 'A');
//		}
//		n /= b;
//	}
//	reverse(ans.begin(), ans.end());
//	cout << ans;
//
//	return 0;
//}