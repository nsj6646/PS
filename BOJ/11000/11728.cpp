#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	vector<int> b(m);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	int i, j;
	for (i = 0, j = 0; i<a.size() || j<b.size();) {
		if (i >= a.size()) {
			for (; j<b.size(); j++) {
				v.push_back(b[j]);
			}
		}
		else if (j >= b.size()) {
			for (; i<a.size(); i++) {
				v.push_back(a[i]);
			}
		}
		else {
			if (a[i] < b[j]) {
				v.push_back(a[i++]);
			}
			else {
				v.push_back(b[j++]);
			}
		}
	}

	for (int x : v) {
		cout << x << ' ';
	}
	return 0;
}