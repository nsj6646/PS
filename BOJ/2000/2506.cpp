#include <stdio.h>

int main()
{
	int arr[100], score[100];
	int N;
	int sum;
	scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sum = score[0] = arr[0];

	for (int i = 1; i < N; i++) {
		if (arr[i] == 0) {
			score[i] = 0;
		}
		else {
			score[i] = ++score[i - 1];
		}
		sum += score[i];
	}
	printf("%d", sum);

	return 0;
}