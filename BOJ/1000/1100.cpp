#include <stdio.h>

char chess[8][9];
int main()
{
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%c", &chess[i][j]);
		}
	}
	//for (int i = 0; i < 8; i++) {
	//	for (int j = 0; j < 9; j++) {
	//		printf("%c", chess[i][j]);
	//	}
	//}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess[i][j] == 'F' && (i + j) % 2 == 0) {
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}