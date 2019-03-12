#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	vector<function<int(int,int)>>d;
	d.push_back([](int x, int y) {
		return x + y;
	});
	d.push_back([](int x, int y) {
		return x - y;
	});
	d.push_back([](int x, int y) {
		return x * y;
	});
	d.push_back([](int x, int y) {
		return x / y;
	});
	d.push_back([](int x, int y) {
		return x % y;
	});
	for (auto &f : d) {
		cout << f(x, y) << '\n';
	}
	return 0;
}