#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int a[100][100];

void print_all(int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> phy(n), agl(n), ment(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
			if (j == 0) {
				phy[i] = a[i][j];
			}
			else if (j == 1) {
				agl[i] = a[i][j];
			}
			else if (j == 2) {
				ment[i] = a[i][j];
			}
		}
	}

	int stat[3] = { 0 };

	sort(phy.begin(), phy.end());
	sort(agl.begin(), agl.end());
	sort(ment.begin(), ment.end());

	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << phy[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << agl[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << ment[i] << ' ';
	}
	cout << '\n';
	cout << '\n';

	int pi,ai,mi;
	pi = ai = mi = 0;
	while (k > 0) {
		if(phy[pi]<agl[ai])
		phy[pi] -= stat[0];
		stat[0] += phy[pi];
		agl[ai] -= stat[1];
		stat[1] += agl[ai];
		ment[mi] -= stat[2];
		stat[2] += ment[mi];
		for (int i = 0; i < n; i++) {
			if (a[i][0] > 0) {
				a[i][0] -= phy[pi];
			}
			if (a[i][1] > 0) {
				a[i][1] -= agl[ai];
			}
			if (a[i][2] > 0) {
				a[i][2] -= ment[mi];
			}

			if (a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0) {
				k -= 1;
			}
		}
		print_all(n);
		pi++;
		ai++;
		mi++;
	}
	cout << stat[0] + stat[1] + stat[2];
	return 0;
}