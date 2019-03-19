#include <bits/stdc++.h>
using namespace std;
#define N		105
struct bus{
	int id,t,p;
}a[N];
int idx;
bus q[N*N];
int front,rear;

int busstop[11];	//-1: 버스없음 0이상: 남은 정차시간
int n,m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		a[i].id=i+1;
		cin>>a[i].t>>a[i].p;
	}
	memset(busstop,-1,sizeof(busstop));

	int timer=0;
	while(1){
		/*시간의 흐름*/
		timer++;

		for(int i=1;i<=n;++i){
			if(busstop[i]>0) busstop[i]--;
		}
		/*버스 탈출*/
		for(int i=1;i<=n;++i){
			if(busstop[i]==-1) continue;
			/*앞차부터*/
			if(busstop[i]>0) break; 	//앞에차가 못가면 뒷차는 당연히 못감
			if(busstop[i]==0){			//정차시간 다됬으면
				busstop[i]=-1;	
			}
		}
		
		/*도착한 버스들 대기열에 넣음*/
		while(idx!=m&&a[idx].t<=timer){
			q[rear++]=a[idx++];
		}

		/*버스정류장으로 들어가기*/
		while(front!=rear&&busstop[n]==-1){
			int i;
			for(i=n-1;i>=1;i--){
				if(busstop[i]>=0){
					break;
				}
			}
			if(q[front].id==m){	//m번째 버스
				cout<<i+1;
				return 0;
			}
			busstop[i+1]=q[front++].p;
		}

	}
    return 0;
}