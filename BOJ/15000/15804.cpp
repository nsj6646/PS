#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct bus{
	int t, p;	//�ýð�, �����ð�
}bus;

int find_index(int n, vector<bool> & isbus) {	//������ ������ ��ġ�� ã�� �Լ�
	for (int i = n-1; i >= 0; i--) {
		if (isbus[i]) {
			return i + 1;
		}
	}
	return 0;
}
int main()
{
	int n, m;
	cin >> n>>m;
	vector<bus> busstop(n);		//����������(�ð�,���������ð�)
	vector<bool> isbus(n);	//����������(������ ����)
	queue<bus> buslist;		//��ü ����
	queue<bus> waitlist;	//��ٸ��� ����

	for (int i = 0; i < m; i++) {
		bus b;
		cin >> b.t >> b.p;
		buslist.push(b);
	}

	int t = 0;		//�ð�
	int size = 0;	//���������忡 �������� ���� ��
	int cnt = 0;	//���� ������ ������ ���° ��������
	int ans;
	while (!buslist.empty() || !waitlist.empty()) {	//�����ٿӰ� ��ٸ��¹����� ���� ��
		t += 1;	//�ð��� �帧

		//���� ���������忡 �ִ� ������ �����ִ� ���� ������.
		if (size > 0) {	//���������忡 �������� ������ ������
			//���������ð� -= 1
			for (int i = 0; i < n; i++) {
				if (isbus[i]) {
					busstop[i].p -= 1;
				}
			}

			for (int i = 0; i < n; i++) {	//�տ����� Ž��
				if (isbus[i]) {	//�������� ������ ������
					if (busstop[i].p <= 0) {	//�����ð��� ��������
						isbus[i] = false;	//��������
						busstop[i].t = busstop[i].p = 0;
						size -= 1;	//������-1
					}
					else {	//�տ� ������ �����ð� ����������
						break;	//�ڿ��ִ� ������ ����
					}
				}
			}
		}

		//���������忡 �����ֱ�
		//��⸮��Ʈ�� ���� �ֱ�
		while (!buslist.empty() && buslist.front().t <= t) {	//�ù����� �����ְ� ������ �ýð��� ������
			waitlist.push(buslist.front());	//��⸮��Ʈ�� �ִ´�
			buslist.pop();

		}

		while (!waitlist.empty()) {	//������� ���� �ֱ�
			if (isbus[n - 1]) {		//n��° �����忡 ������ ������ ������
				break;
			}
			int i = find_index(n,isbus);	//�� ��ġ�� ã�Ƽ�
			busstop[i] = waitlist.front();	//�����ֱ�
			waitlist.pop();
			isbus[i] = true;	//������ ������ ǥ��
			size += 1;	//������+1
			ans = i+1;
		}
	}
	cout << ans;
	return 0;
}

//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//typedef struct bus{
//	int t, p;	//�ýð�, �����ð�
//}bus;
//
//bus busstop[11];
//bool isbus[11];		//����������(������ ����)
//int n, m;
//int find_index() {	//������ ������ ��ġ�� ã�� �Լ�
//	for (int i = 1; i <= n; i++) {
//		if (!isbus[i]) {
//			return i;
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	queue<bus> buses;	//��ü ����
//	//�Է�
//	for (int i = 0; i < m; i++) {
//		bus b;
//		cin >> b.t >> b.p;
//		buses.push(b);
//	}
//	int t = 0;	//�ð�
//	int size = 0;	//���������忡 �������� ���� ��
//	int cnt = 0;	//���� ������ ������ ���° ��������
//	while (!buses.empty()) {	//��� ������ ���ö�����
//		t += 1;	//�ð��� �帧
//		//�������� ������ ������ ���������ð� -1
//		for (int i = 1; i <= n; i++) {
//			if (isbus[i]) {
//				busstop[i].p -= 1;
//			}
//		}
//
//		//���� ���������忡 �ִ� ������ �����ִ� ���� ������.
//		if (size > 0) {	//���������忡 ������ ������
//			for (int i = 1; i <= n; i++) {	//�տ����� Ž��
//				if (isbus[i]) {	//�������� ������ ������
//					if (busstop[i].p <= 0) {	//�����ð��� ��������
//						isbus[i] = false;	//��������
//						size -= 1;	//������-1
//					}
//					else {	//�տ� ������ �����ð� ����������
//						break;	//�ڿ��ִ� ������ ����
//					}
//				}
//			}
//		}
//
//		//���������忡 �����ֱ�
//		while (!isbus[n]) {	//n��° �����忡 ������ ������
//			if (buses.front().t <= t) {	//������� ������ �ýð��� ��ų� ��������
//				int i = find_index();	//�� ��ġ�� ã�Ƽ�
//				busstop[i] = buses.front();	//�����ֱ�
//				buses.pop();
//				isbus[i] = true;	//������ ������ ǥ��
//				size += 1;	//������+1
//				cnt += 1;	//���° ���������� ����
//				if (cnt == m) {	//m��° ����������
//					cout << i;	//����ϰ� ����
//					return 0;
//				}
//			}
//			else {	//���ð� �ȉ����� break;
//				break;
//			}
//		}
//	}
//	return 0;
//}

//#include <iostream>
//#include <queue>
//using namespace std;
//
//struct bus {
//	int busnum;
//	int delaytime;
//	int arrivetime;
//}typedef bus;
//
//bus busline[11];
//queue <bus> buslist;
//queue <bus> waitlist;
//
//void outbus(int t, int n)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		bool flag = true;
//		if (busline[i].busnum != -1)
//		{
//			for (int j = 1; j < i; j++)
//			{
//				if (busline[j].busnum != -1)
//				{
//					flag = false;
//					break;
//				}
//			}
//			if (flag && busline[i].arrivetime + busline[i].delaytime <= t)
//				busline[i].busnum = -1;
//		}
//	}
//	return;
//}
//int checkbusstop(int n)
//{
//	int num = -1;
//	for (int i = n; i > 0; i--)
//	{
//		if (busline[i].busnum == -1)
//			num = i;
//		else
//			break;
//	}
//	return num;
//}
//
//int simulate(int n, int m)
//{
//	int t = 0;
//	while (!buslist.empty() || !waitlist.empty())
//	{
//		outbus(t, n);
//		while (!buslist.empty() && buslist.front().arrivetime == t)
//		{
//			waitlist.push(buslist.front());
//			buslist.pop();
//		}
//		while (checkbusstop(n) != -1 && !waitlist.empty())
//		{
//			bus temp = waitlist.front();
//			waitlist.pop();
//			if (temp.busnum == m)
//				return checkbusstop(n);
//			temp.arrivetime = t;
//			busline[checkbusstop(n)] = temp;
//		}
//		t++;
//	}
//	return -2;
//}
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		busline[i].busnum = -1;
//		busline[i].arrivetime = -1;
//		busline[i].delaytime = -1;
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		bus temp;
//		temp.busnum = i;
//		cin >> temp.arrivetime;
//		cin >> temp.delaytime;
//		buslist.push(temp);
//	}
//	cout << simulate(n, m) << endl;
//	return 0;
//}


//#include <iostream>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//struct data {
//	int   t;
//	int p;
//}tmp;
//
//int arr[101];
//int t, p;
//queue<data> q;
//int time = 0;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		cin >> t >> p;
//
//		tmp.t = t;
//		tmp.p = p;
//		q.push(tmp);
//	}
//	arr[n] = 1; //ex n�� 2�϶� �迭�� ���� 0,0,1
//
//	time = 1;
//
//	while (!q.empty()) { //������ �� ����������
//
//		while (1)//������ ���� ���� �� �ִ� ������ ���������� ���ѹݺ�
//		{
//			if (q.front().t > time) break;  //������ ������ΰ�? �ƴ϶�� while�� Ż��
//											//�´ٸ� ���� �ֱ� �õ�
//			int j = -1;
//			//������ �ִ��� ������ �� �� �ִ°�? 
//			// �迭 ��Ȳ�� 0 0 1 �̶�� j�� 1;
//			// �迭 ��Ȳ�� 1 5 1 �̶�� j -1;
//			for (int i = 0; i < n; i++) {
//				if (arr[i] == 0) j++;
//				else break;
//			}
//			if (j == -1) break;
//			//j�� -1�̶�� ������ �� �� ���� �����̹Ƿ� while�� Ż��
//
//			else {// j�� 0�̻��̶�� 
//				arr[j] = q.front().p; // arr[j]�� ť ���� ���� �ð� ����
//				q.pop(); //���� ��
//				if (q.empty()) { // ������ ������ ���Դٸ�
//					cout << n - j; // j�� ��� ������ ������Ų ��ġ�̹Ƿ� ����ϰ� ����
//					return 0;
//				}
//			}
//		}
//
//		//ex) ���� ������ �迭 ���� 1,5,1
//		for (int i = 0; i < n; i++) {
//			if (arr[i] != 0) {
//				arr[i]--;
//				if (arr[i] <= 0) arr[i] = -1;
//			}
//		}
//
//		//���� ������ �迭 ���� -1,4,1 
//		//0���϶�� -1�� �ٲ��ְ� ���� �� �ִ� ������ �Ǿ��ٴ� ����
//
//		//������ �� ���������� Ž���ϸ鼭 0���� ���� ������ ������ �Ѳ����� ����
//		//���� 0 �ʰ� ���� ������ ���� ���ִ°� �׸��ϰ� for�� Ż��
//		for (int i = n - 1; i >= 0; i--) {
//			if (arr[i] <= 0) arr[i] = 0;
//			else break;
//		}
//		//�ð� ����
//		time++;
//
//	}
//	return 0;
//}