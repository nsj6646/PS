#include <cstdio>

int n;
char a[100][101];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", a[i]);
	}
	int ansH = 0, ansV = 0;

	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (a[i][j] == '.') {
				cnt += 1;
			}
			else {
				if (cnt >= 2) {
					ansH += 1;
				}
				cnt = 0;
			}
		}
		if (cnt >= 2) {
			ansH += 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (a[j][i] == '.') {
				cnt += 1;
			}
			else {
				if (cnt >= 2) {
					ansV += 1;
				}
				cnt = 0;
			}
		}
		if (cnt >= 2) {
			ansV += 1;
		}
	}
	printf("%d %d", ansH,ansV);
	return 0;
}