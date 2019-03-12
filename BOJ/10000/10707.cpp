#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, p;
	cin >> a >> b >> c >> d >> p;

	int A = p * a;
	int B = p - c >= 0 ? b + (p - c)*d : b;
	int ans = A > B ? B : A;
	cout << ans;
	return 0;
}
