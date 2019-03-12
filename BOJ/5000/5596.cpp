#include <cstdio>

int main()
{
	int s=0, t=0;

	for (int i = 0; i < 4; i++) {
		int x;
		scanf("%d", &x);
		s += x;
	}
	for (int i = 0; i < 4; i++) {
		int x;
		scanf("%d", &x);
		t += x;
	}
	printf("%d", s >= t ? s : t);
	return 0;
}