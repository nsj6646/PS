#include <cstdio>
#define PI 3.14159265358979323846
int main()
{
	double r;
	scanf("%lf", &r);
	
	printf("%.6lf\n",r * r*PI);
	printf("%.6lf\n", r * r*2.0);
	return 0;
}