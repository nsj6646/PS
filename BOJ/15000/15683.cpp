#include <bits/stdc++.h>
#define SAFE(x,y)	x>=0&&x<n&&y>=0&&y<m
using namespace std;


struct CCTV
{
	int x, y;
	int type;
	int dir;
	CCTV(int x,int y,int t,int d):x(x),y(y),type(t),dir(d){}
};
vector<CCTV> v;

int n,m;
int a[8][8];
int visited[8][8];
int ans=64;

int dx[6][4][4]{	//[몇번 카메라][방향][[상하좌우] (상:0, 우:1, 하:2, 좌:3)
	{ {0} },
	{ { -1},{ 0 },{1 },{ 0 }},								//1
	{ { 0,0},{ -1,1}},										//2
	{ { -1,0},{ 1,0},{ 1,0},{ -1,0 } },						//3
	{ { -1,0,0 },{ -1,0,1 },{ 0,0,1 },{ -1,0,1 } },			//4
	{ { -1,0,1,0 }},										//5
};
int dy[6][4][4]{	//[몇번 카메라][방향][[상하좌우] (상:0, 우:1, 하:2, 좌:3)
	{ { 0 } },
	{ { 0 },{ 1},{ 0 },{ -1 } },							//1
	{ { -1,1 },{ 0,0} },									//2
	{ { 0,1 },{ 0,1 },{ 0,-1},{ 0,-1 } },					//3
	{ { 0,-1,1 },{ 0,1,0 },{ -1,1,0 },{ 0,-1,0 } },			//4
	{ { 0,1,0,-1 } },										//5
};
int rSize[6]={0,4,2,4,4,1};		//회전 횟수
int dSize[6]={0,1,2,2,3,4};		//방향 횟수

void run(){
	int x,y,type,dir;
	memset(visited,0,sizeof(visited));
	for(int i=0;i<v.size();++i){
		x=v[i].x;
		y=v[i].y;
		type=v[i].type;
		dir=v[i].dir;
		for(int k=0;k<dSize[type];++k){
			int nx=x;
			int ny=y;
			while(SAFE(nx,ny)&&a[nx][ny]!=6){
				visited[nx][ny]=1;
				nx+=dx[type][dir][k];
				ny+=dy[type][dir][k];
			}
		}
	}
}
void dfs(int idx){
	if(idx==v.size()){
		run();
		int cnt=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(!visited[i][j]&&a[i][j]!=6){
					cnt++;
				}
			}
		}
		ans=min(ans,cnt);
		return;
	}
	int t=v[idx].type;
	for(int i=0;i<rSize[t];++i){
		dfs(idx+1);
		v[idx].dir=(v[idx].dir+1)%rSize[t];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>a[i][j];
			if(a[i][j]>=1&&a[i][j]<=5){
				v.emplace_back(i,j,a[i][j],0);
			}
		}
	}

	dfs(0);
	cout<<ans;
	return 0;
}