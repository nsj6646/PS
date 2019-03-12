#include <iostream>
#include <string>
using namespace std;

string a[64];
bool chk(int x, int y, int n) {
	for (int i = y; i <y+n; i++) {
		for (int j = x; j < x+n; j++) {
			if (a[i][j] != a[y][x]) {
				return false;
			}
		}
	}
	return true;
}
void quadtree(int x, int y, int n) {
	if (chk(x, y, n)) {	
		cout<<a[y][x];
	}
	else {
		cout << '(';
		quadtree(x, y, n / 2);
		quadtree(x + n / 2, y, n / 2);
		quadtree(x, y + n / 2, n / 2);
		quadtree(x + n / 2, y + n / 2, n / 2);
		cout << ')';
	}
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	quadtree(0, 0, n);
	return 0;
}