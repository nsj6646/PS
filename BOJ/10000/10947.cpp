#include <cstdio>
#include <ctime>
#include <cstdlib>

int a[46];
int main()
{
	srand(time(NULL));
	for (int i = 0; i < 6; i++) {
		int x = (rand() % 45) + 1;
		if (a[x] == 0) {
			printf("%d ", x);
			a[x] = 1;
		}
		else {
			i--;
		}
	}
	return 0;
}