#define N	100
#include <bits/stdc++.h>

int n, k;
int a[N];
int plug[N];
bool ispluged[N];
bool candidate[N];
int idx;
int ans;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < k; ++i) {
		if (ispluged[a[i]]) {
			continue;
		}
		if (idx < n) {		
			plug[idx++] = a[i];
			ispluged[a[i]] = true;
			continue;
		}
		int t = 0;
		memset(candidate, true, sizeof(candidate));
		for (int j = i+1; j < k; ++j) {
			if (t == n - 1) {
				break;
			}
			if (ispluged[a[j]]&& candidate[a[j]]) {
				candidate[a[j]] = false;
				++t;
			}

		}
		for (int j = 0; j < n;++j) {
			if (candidate[plug[j]]) {
				ispluged[plug[j]] = false;
				ispluged[a[i]] = true;
				plug[j] = a[i];
				ans += 1;
				break;
			}
		}
	}
	printf("%d", ans);


	return 0;
}