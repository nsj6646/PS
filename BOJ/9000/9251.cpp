#define N		1005
#define MAX(X,Y)	(X)>(Y)?(X):(Y)
#include <cstdio>
char a[N];
char b[N];

int lcs[N][N];
int main()
{
	int i, j;
	scanf("%s", a+1);
	scanf("%s", b+1);

	for (i = 1; b[i]; ++i) {		
		for (j = 1; a[j]; ++j) {
			if (b[i] == a[j]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = MAX(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	printf("%d", lcs[i - 1][j - 1]);
	return 0;
}