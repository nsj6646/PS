#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> v(n);
	
	unordered_map<string, string> d;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v[i] = str;
		string rev(str);
		reverse_copy(str.begin(), str.end(), rev.begin());
		d[str] = rev;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (v[i] > v[j] && d[v[i]] < d[v[j]]) {
					ans += 1;
				}
			}
		}
	}
	cout << ans;
	return 0;
}