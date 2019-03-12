#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[20][20];
int ans;
/*
�˰��� ����
��ġ�� �̵�

*/
void up(int board[][20]) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (board[i][j] != 0) {	//���ڰ� ������ -> ��ġ�� ����
				for (int k = i+1; k < n; k++) {
					if (board[k][j] != 0) {	//���ڰ� ������
						if (board[k][j] == board[i][j]) {	//�������ڸ�
							board[i][j] = board[i][j] << 1;	//��ģ�� = 2���ϰ� �ϳ� �����
							board[k][j] = 0;									
						}		
						break;
					}
				}
			}
		}
		//�̵�
		for (int i = 0; i < n; i++) {
			if (board[i][j] == 0) {	//������ ������� �̵���ų�� �ִ�.(����)
				for (int k = i + 1; k < n; k++) {
					if (board[k][j] != 0) {	//���ڰ� ������
						board[i][j] = board[k][j];	//�̵���Ű��
						board[k][j] = 0;		//����
						break;
					}
				}
			}
		}
	}
}
void down(int board[][20]) {
	for (int j = 0; j < n; j++) {
		for (int i = n-1; i >= 0; i--) {
			if (board[i][j] != 0) {	//���ڰ� ������ -> ��ġ�� ����
				for (int k = i - 1; k >= 0; k--) {
					if (board[k][j] != 0) {	//���ڰ� ������
						if (board[k][j] == board[i][j]) {	//�������ڸ�
							board[i][j] = board[i][j] << 1;	//��ģ�� = 2���ϰ� �ϳ� �����
							board[k][j] = 0;
						}
						break;
					}
				}
			}
		}
		//�̵�
		for (int i = n-1; i >=0; i--) {
			if (board[i][j] == 0) {	//������ ������� �̵���ų�� �ִ�.(����)
				for (int k = i -1; k >=0; k--) {
					if (board[k][j] != 0) {	//���ڰ� ������
						board[i][j] = board[k][j];	//�̵���Ű��
						board[k][j] = 0;		//����
						break;
					}
				}
			}
		}
	}
}
void left(int board[][20]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 0) {	//���ڰ� ������ -> ��ġ�� ����
				for (int k = j + 1; k < n; k++) {
					if (board[i][k] != 0) {	//���ڰ� ������
						if (board[i][k] == board[i][j]) {	//�������ڸ�
							board[i][j] = board[i][j] << 1;	//��ģ�� = 2���ϰ� �ϳ� �����
							board[i][k] = 0;
						}
						break;
					}
				}
			}
		}
		//�̵�
		for (int j = 0; j < n;j++) {
			if (board[i][j] == 0) {	//������ ������� �̵���ų�� �ִ�.(����)
				for (int k = j + 1; k < n; k++) {
					if (board[i][k] != 0) {	//���ڰ� ������
						board[i][j] = board[i][k];	//�̵���Ű��
						board[i][k] = 0;		//����
						break;
					}
				}
			}
		}
	}
}
void right(int board[][20]) {
	for (int i = 0; i < n; i++) {
		for (int j = n-1; j >=0; j--) {
			if (board[i][j] != 0) {	//���ڰ� ������ -> ��ġ�� ����
				for (int k = j - 1; k >=0; k--) {
					if (board[i][k] != 0) {	//���ڰ� ������
						if (board[i][k] == board[i][j]) {	//�������ڸ�
							board[i][j] = board[i][j] << 1;	//��ģ�� = 2���ϰ� �ϳ� �����
							board[i][k] = 0;
						}
						break;
					}
				}
			}
		}
		//�̵�
		for (int j = n-1; j >=0; j--) {
			if (board[i][j] == 0) {	//������ ������� �̵���ų�� �ִ�.(����)
				for (int k = j - 1; k >=0; k--) {
					if (board[i][k] != 0) {	//���ڰ� ������
						board[i][j] = board[i][k];	//�̵���Ű��
						board[i][k] = 0;		//����
						break;
					}
				}
			}
		}
	}
}
void printall(int board[][20]) {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

void go(int now[][20],int cnt) {
	if (cnt == 5) {
		//printall(now);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans = max(ans, now[i][j]);
			}
		}
		return;
	}
	int next[20][20];
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < n; i++) {
			memcpy(next[i], now[i], sizeof(int)*n);
		}
		switch (k)
		{
		case 0:up(next);
			break;
		case 1:down(next);
			break;
		case 2:left(next);
			break;
		case 3:right(next);
			break;
		}
		go(next, cnt + 1);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	//right(a);
	//printall(a);
	//left(a);
	//printall(a);

	//up(a);
	//printall(a);
	//down(a);
	//printall(a);

	go(a, 0);
	cout << ans;
	return 0;
}