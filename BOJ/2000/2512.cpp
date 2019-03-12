#include <cstdio>

int a[10000];
int main()
{
	int n;
	scanf("%d", &n);
	int sum = 0, min = 1, max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		if (a[i] > max) {
			max = a[i];
		}
	}
	int m;
	scanf("%d", &m);
	if (sum <= m) {
		printf("%d", max);
	}
	else {	
		while (min <= max) {
			//printf("%d %d\n", min, max);
			sum = 0;
			int mid = (min + max) / 2;
			for (int i = 0; i < n; i++) {
				if(a[i]>=mid){
					sum += mid;
				}
				else {
					sum += a[i];
				}
			}
			//printf("%d\n", sum);
			if (sum <= m) {
				min = mid + 1;
			}
			else {
				max = mid - 1;
			}
		}
		printf("%d", max);
	}
	return 0;
}