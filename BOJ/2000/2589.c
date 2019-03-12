#include <stdio.h>
#include <string.h>
#define N 50
#define SIZE 2500

int r, c;
char a[N][N];
int visited[N][N];

typedef struct point {
	int x, y;
}point;

point queue[SIZE];
int front;
int rear;

void queueInit() {
	front = 0;
	rear = 0;
}

int queueIsEmpty() {
	return (front == rear);
}
void enqueue(point value) {

}
point dequeue() {

}
void bfs(int x, int y) {
	memset(visited, 0, sizeof(visited));
	queueInit();
	visited[x][y] = 1;

}
void printall() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf(" %c", &a[i][j]);
		}
	}



	return 0;
}