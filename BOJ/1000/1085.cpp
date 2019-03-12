#include <iostream>
#include <algorithm>
using namespace std;

int x, y, w, h;
int main()
{
	cin >> x >> y >> w >> h;
	int x0 = x - 0;
	int y0 = y - 0;
	int wx = w - x;
	int hy = h - y;
	int ans = min({ x0,y0,wx,hy });
	cout << ans;
	return 0;
}