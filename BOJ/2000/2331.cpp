#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool check[236197];

int main()
{
	int a, p;
	cin >> a >> p;
	vector<int> d;
	
	while (!check[a]) {
		d.push_back(a);
		check[a] = true;
		int next = 0;
		while (a > 0) {
			next += (int)pow(a % 10, p);
			a /= 10;
		}
		a = next;
	}
	int cnt = 0;
	for (int i = 0; d[i] != a; i++) {
		cnt += 1;
	}
	cout << cnt;
	return 0;
}
/*
#include <iostream>
using namespace std;
int check[1000000];
int pow(int x, int p) {
	int ans = 1;
	for (int i = 0; i<p; i++) {
		ans = ans * x;
	}
	return ans;
}
int next(int a, int p) {
	int ans = 0;
	while (a > 0) {
		ans += pow(a % 10, p);
		a /= 10;
	}
	return ans;
}
int length(int a, int p, int cnt) {
	if (check[a] != 0) {
		return check[a] - 1;
	}
	check[a] = cnt;
	int b = next(a, p);
	return length(b, p, cnt + 1);
}
int main() {
	int a, p;
	cin >> a >> p;
	cout << length(a, p, 1) << '\n';
	return 0;
}
*/