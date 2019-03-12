#define MAX_L		1000001
#include <cstdio>

struct NODE {
	char data;
	struct NODE *next;
	struct NODE *prev;
};

NODE nodePool[MAX_L + 2];
int nodeIdx;
NODE* newNode() { return &nodePool[nodeIdx++]; }

struct LIST {
	NODE *head;
	NODE *tail;
	NODE *cur;

	void init() {
		head = newNode();
		tail = newNode();
		head->next = tail;
		tail->prev = head;
		cur = head;
	}
};
LIST list;
char input[MAX_L];
void init() {
	nodeIdx = 0;
	list.init();
}

void backspace() {
	if (list.cur == list.head) {
		/*nothing*/
		return;
	}
	list.cur->next->prev = list.cur->prev;
	list.cur->prev->next = list.cur->next;
	list.cur = list.cur->prev;
}
void moveLeft() {
	if (list.cur == list.head) {
		/*nothing*/
		return;
	}
	list.cur = list.cur->prev;
}
void moveRight() {
	if (list.cur->next == list.tail) {
		/*nothing*/
		return;
	}
	list.cur = list.cur->next;
}
void insert(char c) {
	NODE *temp = newNode();
	temp->data = c;
	temp->next = list.cur->next;
	temp->prev = list.cur;
	temp->next->prev = temp;
	temp->prev->next = temp;
	list.cur = temp;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		init();
		scanf("%s", input);
		for (register int i = 0; input[i]; ++i) {
			if (input[i] == '-') {
				backspace();
			}
			else if (input[i] == '<') {
				moveLeft();
			}
			else if (input[i] == '>') {
				moveRight();
			}
			else {
				insert(input[i]);
			}
		}

		for (register NODE*temp = list.head->next; temp != list.tail; temp = temp->next) {
			printf("%c", temp->data);
		}
		printf("\n");
	}
	return 0;
}




//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//int n;
//stack<char> ls, rs;
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//	cin >> n;
//	for (int tc = 1; tc <= n; tc++) {
//		string str;
//		cin >> str;
//		for (char c : str) {
//			if (c == '<') {
//				if (ls.empty()) continue;
//				rs.push(ls.top());
//				ls.pop();
//			}
//			else if (c == '>') {
//				if (rs.empty()) continue;
//				ls.push(rs.top());
//				rs.pop();
//			}
//			else if (c == '-') {
//				if (ls.empty()) continue;
//				ls.pop();
//			}
//			else {
//				ls.push(c);
//			}
//		}
//		while (!ls.empty()) {
//			rs.push(ls.top());
//			ls.pop();
//		}
//		while (!rs.empty()) {
//			cout << rs.top();
//			rs.pop();
//		}
//		cout << '\n';
//	}
//
//	return 0;
//}