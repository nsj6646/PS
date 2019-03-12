#include <iostream>
#include <algorithm>
using namespace std;

int mx, a[9];
int main()
{
	int n, index;
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	

	cout << mx << '\n';
	cout << max_element(a, a + 9)-a+1;
	return 0;
}
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int idx[100];
//int a[9];
//int main()
//{
//	for (int i = 0; i < 9; i++) {
//		cin >> a[i];
//		idx[a[i]] = i;
//	}
//	sort(a, a + 9);
//	cout << a[8] << '\n';
//	cout << idx[a[8]] + 1;
//	return 0;
//}
