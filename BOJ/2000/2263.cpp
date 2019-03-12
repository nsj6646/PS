#include <iostream>

using namespace std;

int inorder[100000];
int postorder[100000];
int position[100001];


void preorder(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe) {
		return;
	}
	int root = postorder[pe];
	int ir = position[root];
	cout << root << ' ';
	int l = ir - is;
	preorder(is, ir -1,ps,ps+l-1);
	preorder(ir + 1, ie, ps+l, pe-1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}
	for (int i = 0; i<n; i++) {
		position[inorder[i]] = i;
	}
	preorder(0, n - 1, 0, n - 1);
	return 0;
}