#include <iostream>
#include <string>
using namespace std;

typedef struct node
{
	int data;
	node *next;
	node *prev;
}node;
class deque {
private:
	int numofData;
	node *head;
	node *tail;
public:
	void push_front(int X);
	void push_back(int X);
	int pop_front();
	int pop_back();
	int size();
	int empty();
	int front();
	int back();
	deque() {
		numofData = 0;
		head = NULL;
		tail = NULL;
	}
	~deque() {
		while (!this->empty()) {
			node *temp = head;
			if (head->next != NULL) {
				head = head->next;
			}
			numofData--;
			delete temp;
		}
	}
};
//push_front X : 정수 X를 덱의 앞에 넣는다.
//push_back X : 정수 X를 덱의 뒤에 넣는다.
//pop_front : 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다.만약, 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
//pop_back : 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다.만약, 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
//size : 덱에 들어있는 정수의 개수를 출력한다.
//empty : 덱이 비어있으면 1을, 아니면 0을 출력한다.
//front : 덱의 가장 앞에 있는 정수를 출력한다.만약 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
//back : 덱의 가장 뒤에 있는 정수를 출력한다.만약 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
void deque::push_front(int X) {
	node *temp = new node;
	temp->data = X;
	if (this->empty()) {
		temp->next = NULL;
		this->tail = temp;
	}
	else {
		temp->next = this->head;
		this->head->prev = temp;
	}
	temp->prev = NULL;
	this->head = temp;
	this->numofData++;
}
void deque::push_back(int X) {
	node *temp = new node;
	temp->data = X;
	if (this->empty()) {
		temp->prev = NULL;
		this->head = temp;
	}
	else {
		temp->prev = this->tail;
		this->tail->next = temp;
	}
	temp->next = NULL;
	this->tail = temp;
	this->numofData++;
}
int deque::pop_front() {
	if (this->empty()) {
		return -1;
	}
	node *temp = this->head;
	int x = temp->data;
	if (temp->next != NULL) {
		this->head = temp->next;
		this->head->prev = NULL;
	}
	delete temp;
	this->numofData--;
	return x;
}
int deque::pop_back() {
	if (this->empty()) {
		return -1;
	}
	node *temp = this->tail;
	int x = temp->data;
	if (temp->prev != NULL) {
		this->tail = temp->prev;
		this->tail->next = NULL;
	}
	delete temp;
	this->numofData--;
	return x;
}
int deque::size() {
	return this->numofData;
}
int deque::empty() {
	if (this->numofData != 0) {
		return 0;
	}
	return 1;
}
int deque::front() {
	if (this->empty()) {
		return -1;
	}
	return this->head->data;
}
int deque::back() {
	if (this->empty()) {
		return -1;
	}
	return this->tail->data;
}
int main()
{
	deque *d = new deque();
	int N;
	cin >> N;
	string order;
	int X;
	while (N--) {
		cin >> order;
		if (order == "push_front") {
			cin >> X;
			d->push_front(X);
		}
		else if (order == "push_back") {
			cin >> X;
			d->push_back(X);
		}
		else if (order == "pop_front") {
			cout << d->pop_front() << '\n';
		}
		else if (order == "pop_back") {
			cout << d->pop_back() << '\n';
		}
		else if (order == "size") {
			cout << d->size() << '\n';
		}
		else if (order == "empty") {
			cout << d->empty() << '\n';
		}
		else if (order == "front") {
			cout << d->front() << '\n';
		}
		else if (order == "back") {
			cout << d->back() << '\n';
		}
	}
	delete d;
	return 0;
}