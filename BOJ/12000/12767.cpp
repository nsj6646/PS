#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

typedef struct Node {
	int val;
	struct Node *left;
	struct Node *right;
	Node() {
		val = 0;
		left = NULL;
		right = NULL;
	}
}node;

string preorder(node *root) {
	string ans;
	ans.push_back('V');
	if (root->left) {
		ans.push_back('L');
		ans+=preorder(root->left);
		ans.push_back('l');
	}
	if (root->right) {
		ans.push_back('R');
		ans+=preorder(root->right);
		ans.push_back('r');
	}
	ans.push_back('v');
	return ans;
}

void remove(node *root) {
	if (root->left) {
		remove(root->left);
	}
	if (root->right) {
		remove(root->right);
	}
	delete root;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	set<string> s;
	for (int i = 0; i < n; i++) {
		vector<int> a(k);
		for (int j = 0; j < k; j++) {
			cin >> a[j];
		}
		node *root = new node;
		root->val = a[0];
		for (int j = 1; j < k; j++) {
			node *cur = root;
			while (true) {
				if (a[j] < cur->val) {
					if (cur->left == NULL) {
						cur->left = new node;
						cur->left->val = a[j];
						break;
					}
					else {
						cur = cur->left;
					}
				}
				else if (a[j] > cur->val) {
					if (cur->right == NULL) {
						cur->right = new node;
						cur->right->val = a[j];
						break;
					}
					else {
						cur = cur->right;
					}
				}
				else {
					break;
				}
			}
		}
		s.insert(preorder(root));
		remove(root);
	}
	cout << s.size();
	return 0;
}