#define N		2000
#include <cstdio>

struct POINT {
	int x, y;
	POINT(int x=0, int y=0) :x(x), y(y) {}
};
POINT points[N+1];
int n, q;
int qx, qy;
int state;
int min_point1, min_point2;
int dist = -1;
int get_distance(int x1, int x2, int y1, int y2) {
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}
int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		points[i] = {x,y };
	}
	for (int i = 0; i < q; ++i) {
		scanf("%d %d", &qx, &qy);
		for (int j = 1; j <= n; ++j) {
			dist = -1;
			int temp = get_distance(points[j].x, qx, points[j].y, qy);
			if (dist == -1 || dist > temp) {
				dist = temp;
				min_point1 = j;
				state = 1;
			}
			else if (dist == temp&&state==1) {
				state = 2;
				min_point2 = j;
			}
			else if (dist == temp && state == 2) {
				state = 3;
			}
		}
		switch (state)
		{
		case 1:
			printf("REGION %d\n", min_point1);
			break;
		case 2:
			printf("LINE %d %d\n", min_point1, min_point2);
			break;
		case 3:
			printf("POINT\n");
			break;
		}
	}
	return 0;
}