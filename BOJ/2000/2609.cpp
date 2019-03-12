#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
int main()
{
	int a, b;
	cin >> a >> b;
	int g = gcd(a, b);
	cout << g << '\n' << a*b/g;
	return 0;
}