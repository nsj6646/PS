#include <bits/stdc++.h>
using namespace std;

int n, kim, im;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> kim >> im;
	int k;
	for (k = 1; k < n; k *= 2);
	n = k;
	int r = 1;
	while (kim != im) {
		for (int i = 1; i <= n; i += 2) {
			if (i == kim || i + 1 == kim) {
				kim = i/2+1;
			}
			if (i == im || i + 1 == im) {
				im = i/2+1;
			}
		}
		n /= 2;
		r += 1;
	}
	cout << r - 1;

	return 0;
}