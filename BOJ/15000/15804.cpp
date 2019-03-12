#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct bus{
	int t, p;	//올시간, 정차시간
}bus;

int find_index(int n, vector<bool> & isbus) {	//버스가 정차할 위치를 찾는 함수
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
	vector<bus> busstop(n);		//버스정류장(시간,정차남은시간)
	vector<bool> isbus(n);	//버스정류장(버스의 유무)
	queue<bus> buslist;		//전체 버스
	queue<bus> waitlist;	//기다리는 버스

	for (int i = 0; i < m; i++) {
		bus b;
		cin >> b.t >> b.p;
		buslist.push(b);
	}

	int t = 0;		//시간
	int size = 0;	//버스정류장에 정차중인 버스 수
	int cnt = 0;	//지금 들어오는 버스가 몇번째 버스인지
	int ans;
	while (!buslist.empty() || !waitlist.empty()) {	//버스다왓고 기다리는버스도 없을 때
		t += 1;	//시간의 흐름

		//먼저 버스정류장에 있는 버스중 갈수있는 버스 보낸다.
		if (size > 0) {	//버스정류장에 정차중인 버스가 있으면
			//정차남은시간 -= 1
			for (int i = 0; i < n; i++) {
				if (isbus[i]) {
					busstop[i].p -= 1;
				}
			}

			for (int i = 0; i < n; i++) {	//앞에부터 탐색
				if (isbus[i]) {	//정차중인 버스가 있으면
					if (busstop[i].p <= 0) {	//정차시간이 지났으면
						isbus[i] = false;	//버스보냄
						busstop[i].t = busstop[i].p = 0;
						size -= 1;	//버스수-1
					}
					else {	//앞에 버스가 정차시간 안지났으면
						break;	//뒤에있는 버스도 못감
					}
				}
			}
		}

		//버스정류장에 버스넣기
		//대기리스트에 먼저 넣기
		while (!buslist.empty() && buslist.front().t <= t) {	//올버스가 남아있고 버스가 올시간이 됬으면
			waitlist.push(buslist.front());	//대기리스트에 넣는다
			buslist.pop();

		}

		while (!waitlist.empty()) {	//대기중인 버스 넣기
			if (isbus[n - 1]) {		//n번째 정류장에 버스가 있으면 못넣음
				break;
			}
			int i = find_index(n,isbus);	//들어갈 위치를 찾아서
			busstop[i] = waitlist.front();	//버스넣기
			waitlist.pop();
			isbus[i] = true;	//버스가 있음을 표시
			size += 1;	//버스수+1
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
//	int t, p;	//올시간, 정차시간
//}bus;
//
//bus busstop[11];
//bool isbus[11];		//버스정류장(버스의 유무)
//int n, m;
//int find_index() {	//버스가 정차할 위치를 찾는 함수
//	for (int i = 1; i <= n; i++) {
//		if (!isbus[i]) {
//			return i;
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	queue<bus> buses;	//전체 버스
//	//입력
//	for (int i = 0; i < m; i++) {
//		bus b;
//		cin >> b.t >> b.p;
//		buses.push(b);
//	}
//	int t = 0;	//시간
//	int size = 0;	//버스정류장에 정차중인 버스 수
//	int cnt = 0;	//지금 들어오는 버스가 몇번째 버스인지
//	while (!buses.empty()) {	//모든 버스가 들어올때까지
//		t += 1;	//시간의 흐름
//		//정차중인 버스가 있으면 정차남은시간 -1
//		for (int i = 1; i <= n; i++) {
//			if (isbus[i]) {
//				busstop[i].p -= 1;
//			}
//		}
//
//		//먼저 버스정류장에 있는 버스중 갈수있는 버스 보낸다.
//		if (size > 0) {	//버스정류장에 버스가 있으면
//			for (int i = 1; i <= n; i++) {	//앞에부터 탐색
//				if (isbus[i]) {	//정차중인 버스가 있으면
//					if (busstop[i].p <= 0) {	//정차시간이 지났으면
//						isbus[i] = false;	//버스보냄
//						size -= 1;	//버스수-1
//					}
//					else {	//앞에 버스가 정차시간 안지났으면
//						break;	//뒤에있는 버스도 못감
//					}
//				}
//			}
//		}
//
//		//버스정류장에 버스넣기
//		while (!isbus[n]) {	//n번째 정류장에 버스가 없으면
//			if (buses.front().t <= t) {	//대기중인 버스가 올시간이 됬거나 지났으면
//				int i = find_index();	//들어갈 위치를 찾아서
//				busstop[i] = buses.front();	//버스넣기
//				buses.pop();
//				isbus[i] = true;	//버스가 있음을 표시
//				size += 1;	//버스수+1
//				cnt += 1;	//몇번째 버스였는지 세기
//				if (cnt == m) {	//m번째 버스였으면
//					cout << i;	//출력하고 종료
//					return 0;
//				}
//			}
//			else {	//대기시간 안됬으면 break;
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
//	arr[n] = 1; //ex n이 2일때 배열의 상태 0,0,1
//
//	time = 1;
//
//	while (!q.empty()) { //버스가 다 빠질때까지
//
//		while (1)//버스가 들어고 빠질 수 있는 조건이 여러가지라 무한반복
//		{
//			if (q.front().t > time) break;  //버스가 대기중인가? 아니라면 while문 탈출
//											//맞다면 버스 넣기 시도
//			int j = -1;
//			//어디까지 최대한 버스가 들어갈 수 있는가? 
//			// 배열 상황이 0 0 1 이라면 j는 1;
//			// 배열 상황이 1 5 1 이라면 j -1;
//			for (int i = 0; i < n; i++) {
//				if (arr[i] == 0) j++;
//				else break;
//			}
//			if (j == -1) break;
//			//j가 -1이라면 버스가 들어갈 수 없는 상태이므로 while문 탈출
//
//			else {// j가 0이상이라면 
//				arr[j] = q.front().p; // arr[j]에 큐 버스 정차 시간 삽입
//				q.pop(); //버스 뺌
//				if (q.empty()) { // 마지막 버스가 들어왔다면
//					cout << n - j; // j가 방금 버스를 정차시킨 위치이므로 출력하고 종료
//					return 0;
//				}
//			}
//		}
//
//		//ex) 현재 정류장 배열 상태 1,5,1
//		for (int i = 0; i < n; i++) {
//			if (arr[i] != 0) {
//				arr[i]--;
//				if (arr[i] <= 0) arr[i] = -1;
//			}
//		}
//
//		//현재 정류장 배열 상태 -1,4,1 
//		//0이하라면 -1로 바꿔주고 빠질 수 있는 조건이 되었다는 상태
//
//		//정류장 맨 끝에서부터 탐색하면서 0보다 작은 값들이 나오면 한꺼번에 빼줌
//		//만약 0 초과 값이 나오는 순간 빼주는거 그만하고 for문 탈출
//		for (int i = n - 1; i >= 0; i--) {
//			if (arr[i] <= 0) arr[i] = 0;
//			else break;
//		}
//		//시간 증가
//		time++;
//
//	}
//	return 0;
//}