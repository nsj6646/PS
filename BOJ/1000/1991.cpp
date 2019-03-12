#include <iostream>
using namespace std;

int A[26][2];
void preorder(int node);
void inorder(int node);
void postorder(int node);
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char p, lc, rc;
		cin >> p >> lc >> rc;
		p = p - 'A';
		if (lc == '.') {
			lc = -1;
		}
		else {
			lc = lc - 'A';
		}
		if (rc == '.') {
			rc = -1;
		}
		else {
			rc = rc - 'A';
		}
		A[p][0] = lc;
		A[p][1] = rc;

	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	return 0;
}
void preorder(int node) {
	if (node == -1) {
		return;
	}
	cout << (char)(node + 'A');
	preorder(A[node][0]);
	preorder(A[node][1]);
}
void inorder(int node) {
	if (node == -1) {
		return;
	}
	inorder(A[node][0]);
	cout << (char)(node + 'A');
	inorder(A[node][1]);
}
void postorder(int node) {
	if (node == -1) {
		return;
	}
	postorder(A[node][0]);
	postorder(A[node][1]);
	cout << (char)(node + 'A');
}
/*
#include <iostream>
using namespace std;
int a[50][2];
void preorder(int x) {
	if (x == -1) return;
	cout << (char)(x + 'A');
	preorder(a[x][0]);
	preorder(a[x][1]);
}
void inorder(int x) {
	if (x == -1) return;
	inorder(a[x][0]);
	cout << (char)(x + 'A');
	inorder(a[x][1]);
}
void postorder(int x) {
	if (x == -1) return;
	postorder(a[x][0]);
	postorder(a[x][1]);
	cout << (char)(x + 'A');
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char x, y, z;
		cin >> x >> y >> z;
		x = x - 'A';
		if (y == '.') {
			a[x][0] = -1;
		}
		else {
			a[x][0] = y - 'A';
		}
		if (z == '.') {
			a[x][1] = -1;
		}
		else {
			a[x][1] = z - 'A';
		}
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
	return 0;
}
*/