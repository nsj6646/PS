#define MAX(X,Y)	(X)>(Y)?(X):(Y)
#include <iostream>
#include <vector>

using namespace std;
int ans;

void dfs(vector<int> v,int e) {
	if (v.size() == 2) {
		ans=MAX(ans, e);
		return;
	}
	int sz = v.size();
	vector<int> next(sz - 1);
	int w;
	for (int i = 1; i < sz - 1; ++i) {
		w = v[i-1]*v[i+1];
		for (int j = 0; j < i; ++j) {
			next[j] = v[j];
		}
		for (int j = i; j < sz-1; ++j) {
			next[j] = v[j+1];
		}
		dfs(next, e + w);
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	dfs(v,0);
	cout << ans;
	return 0;
}