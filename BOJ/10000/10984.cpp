#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		int n;
		scanf("%d", &n);
		int total = 0;
		double gpa = 0;
		for (int i = 0; i < n; ++i) {
			int c;
			double g;
			scanf("%d %lf", &c, &g);
			total += c;
			gpa += c * g;
		}
		
		gpa /= total;
		gpa += 0.00001;
		printf("%d %.1lf\n", total, gpa);
	}
	return 0;
}