#include <stdio.h>
int set[20000001];
int main()
{
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		set[num + 10000000]++;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		printf("%d ", set[num + 10000000]);
	}
	return 0;
}