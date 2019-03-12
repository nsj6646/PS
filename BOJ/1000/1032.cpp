#include <cstdio>

char filename[50][51];
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", filename[i]);
	}


	int flag = -1;
	for (int k = 0; filename[0][k] != '\0'; k++) {
		for (int i = 1; i < n; i++) {
			if (filename[i][k] != filename[0][k]) {
				filename[0][k] = '?';
			}
		}
	}

	printf("%s", filename[0]);
	return 0;
}