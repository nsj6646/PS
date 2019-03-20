#include <bits/stdc++.h>
#define SAFE(X,Y)	(X)>=0&&(X)<12&&(Y)>=0&&(Y)<6
char a[12][6];
bool visited[12][6];
char save[12][6];
struct point{
	int x,y;
	point(int x=0,int y=0):x(x),y(y){}
};

point q[100];
int front,rear;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void init(){
	memset(visited,0,sizeof(visited));
	front=rear=0;
	memcpy(save,a,sizeof(save));	//복원을 위해//백업배열
}
bool bfs(int sx,int sy,char c){
	init();
	a[sx][sy]='.';
	q[rear++]={sx,sy};
	visited[sx][sy]=true;
	int cnt=1;
	while(front!=rear){
		point &now=q[front++];
		int x=now.x;
		int y=now.y;
		for(int k=0;k<4;++k){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if(SAFE(nx,ny)&&a[nx][ny]==c&&!visited[nx][ny]){
				a[nx][ny]='.';
				visited[nx][ny]=true;
				q[rear++]={nx,ny};
				cnt++;
			}
		}
	}
	if(cnt>=4){
		return true;
	}
	else{
		memcpy(a,save,sizeof(a));
		return false;
	}
}
void move(){
	char mq[12];
	int mfront,mrear;

	for(int j=0;j<6;++j){
		mfront=mrear=0;
		for(int i=11;i>=0;--i){
			if(a[i][j]=='.') continue;
			mq[mrear++]=a[i][j];
			a[i][j]='.';
		}

		for(int i=11;mfront!=mrear;--i){
			a[i][j]=mq[mfront++];
		}
	}
}

int main()
{
	for(int i=0;i<12;++i){
		for(int j=0;j<6;++j){
			scanf(" %c",&a[i][j]);
		}
	}

	int ans=-1;
	bool boom=true;	//연쇄작용여부
	while(boom){
		boom=false;
		ans++;
		//영역구하기
		for(int i=0;i<12;++i){
			for(int j=0;j<6;++j){
				if(a[i][j]!='.'&&!visited[i][j]){
					bool res=bfs(i,j,a[i][j]);
					if(!boom) boom=res;
				}
			}
		}

		move();
	}
	printf("%d",ans);
	
    return 0;
}