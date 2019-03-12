#include <cstdio>

int ans;
int q[100][3];
int strike[100], ball[100];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%1d", &q[i][j]);
		}
		scanf("%d %d", &strike[i], &ball[i]);
	}
	for (int x = 111; x <= 999; x++) {
		bool ispossible = true;
		int a[3] = { x / 100,(x / 10) % 10,x % 10 };
		/*except 0*/
		if ((a[0] == 0 || a[1] == 0 || a[2] == 0)||(a[0]==a[1]||a[0]==a[2]||a[1]==a[2])) {
			continue;
		}
		/*check*/
		for (int i = 0; i < n; i++) {
			int s = 0, b = 0;
			/*strike*/
			for (int j = 0; j < 3; j++) {
				if (q[i][j] == a[j]) {
					s += 1;
				}
				/*ball*/
				for (int k = 0; k < 3; k++) {
					if (k != j && q[i][k] == a[j]) {
						b += 1;
					}
				}
			}
			if (s == strike[i] && b == ball[i]) {
				continue;
			}
			else {
				ispossible = false;
				break;
			}
		}
		if (ispossible) {
			ans += 1;
		}
	}
	printf("%d", ans);
	return 0;
}