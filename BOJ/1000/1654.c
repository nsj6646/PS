//#include <stdio.h>
//
//int main()
//{
//	int i, j = 0;
//	long long max = 0, min = 0, m = 0;
//	int n = 0;
//	scanf("%d", &n);
//	scanf("%lld", &m);
//	long long s[10001] = { 0, };
//
//	for (i = 0; i < n; i++) {
//		scanf("%lld", &s[i]);
//	}
//	for (i = 0; i < n; i++) {
//		if (max < s[i]) {
//			max = s[i];
//		}
//	}
//	while (min <= max) {
//		int cnt = 0;
//		long long mid = (min + max) / 2;
//		for (i = 0; i < n; i++) {
//			cnt += s[i] / mid;
//			if (cnt >= m) {
//				min = mid + 1;
//			}
//			else {
//				max = mid - 1;
//			}
//
//		}
//	}
//	printf("%d", (int)max);
//	return 0;
//}
#include <stdio.h>

long long lan[10000];
int main()
{
	int K, N;//K : 랜선의 개수, N : 필요한 랜선의 개수
	long long min = 1, max = 0, mid;
	int count;
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++) {
		scanf("%lld", &lan[i]);
		if (max < lan[i]) {
			max = lan[i];
		}
	}
	while (min <= max) {
		count = 0;
		mid = (min + max) / 2;
		for (int i = 0; i < K; i++) {
			count += lan[i] / mid;
		}
		if (count >= N) {
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}
	printf("%lld", max);
	
	return 0;
}
