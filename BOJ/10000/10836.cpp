#include <cstdio>
#include <algorithm>
using namespace std;

int a[700][700];
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	for (int i = 0; i < m; i++) {
		fill(a[i], a[i] + m, 1);
	}

	while (n--) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

		for (int i = m - 1; i >= 1; i--) {
			if (x > 0) {
				x -= 1;
			}
			else if (y > 0) {
				y -= 1;
				a[i][0] += 1;
			}
			else if (z > 0) {
				z -= 1;
				a[i][0] += 2;
			}
		}

		for (int i = 0; i < m; i++) {
			if (x > 0) {
				x -= 1;
			}
			else if (y > 0) {
				y -= 1;
				a[0][i] += 1;
			}
			else if (z > 0) {
				z -= 1;
				a[0][i] += 2;
			} 
		}
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < m; j++) {
			a[i][j] = max(a[i - 1][j], max(a[i - 1][j - 1], a[i][j - 1]));
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}