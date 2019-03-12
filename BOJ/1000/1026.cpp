#include <stdio.h>

int S();
int N;
int A[51], B[51];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}
	int temp;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (A[j] > A[j + 1]) {
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (B[j] < B[j + 1]) {
				temp = B[j];
				B[j] = B[j + 1];
				B[j + 1] = temp;
			}
		}
	}

	printf("%d", S());
	return 0;
}
int S() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i] * B[i];
	}
	return sum;
}