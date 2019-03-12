#include <iostream>
#include <map>
using namespace std;

map<int, int> d;
int check(int key, int k) {
	int flag = -1;
	int left = key, right = key;
	for (int i = 1; i <= k; i++) {
		if (left - i >= 0) {
			if (d.count(left - i) != 0) {
				flag = left - i;
			}
		}
		if (right + i <= 1000000000) {
			if (d.count(right + i) != 0) {
				if (flag != -1) {
					return -2;		//�Ѵ�����
				}
				flag = right + i;
				return flag;	//left�� ���µ� right�� ����
			}
			else if (flag != -1) {	//right�� ���µ� left�� ����
				return flag;
			}
		}
		if (left - i < 0 && right + i > 1000000000) {
			break;
		}
	}
	return -1;	//�� ����
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		int key, value;
		cin >> key >> value;
		d[key] = value;
	}
	for (int i = 0; i < m; i++) {
		int cmd, key, value;
		cin >> cmd;
		if (cmd == 1) {
			cin >> key >> value;
			d[key] = value;
		}
		else if (cmd == 2) {
			cin >> key >> value;
			if (d.count(key) != 0) {		//������ �װɷ� ��ü
				d[key] = value;
			}
			else {			//������ ���ǰ˻�
				int chk = check(key, k);
				if (chk == -1 || chk == -2) {		//������ key��������(���ų� �ߺ�)
					continue;	//����
				}
				else {
					d[chk] = value;
				}
			}
		}
		else {
			cin >> key;
			if (d.count(key) != 0) {		//������ �װ����
				cout << d[key] << '\n';
			}
			else {			//������ ���ǰ˻�
				int chk = check(key, k);
				if (chk == -1) {		//key������
					cout << "-1\n";
				}
				else if(chk == -2){		//key�� �ΰ��̻� ����
					cout << "?\n";
				}
				else {
					cout << d[chk] << '\n';
				}
			}
		}
	}
	return 0;
}