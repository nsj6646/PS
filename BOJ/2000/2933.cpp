#include <bits/stdc++.h>
#define N       105
#define SAFE(X,Y)	(X)>=0&&(X)<=r&&(Y)>=0&&(Y)<c
char a[N][N];
int h[N];
bool visited[N][N];
struct point{
	int x,y;
	point(int x=0,int y=0):x(x),y(y){}
};
point q[N*N];
int front,rear;
int r,c;
int n;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

point cluster[N*N];   //공중에 떠있는 클러스터의 좌표
int sz;

void init(){
    memset(visited,0,sizeof(visited));
    front=rear=0;
}

void bfs(int sx,int sy){
    init();
    visited[sx][sy]=true;
    q[rear++]={sx,sy};
    while(front!=rear){
        int x=q[front].x;
        int y=q[front++].y;
        for(int k=0;k<4;++k){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(SAFE(nx,ny)&&a[nx][ny]=='x'&&!visited[nx][ny]){
                visited[nx][ny]=true;
                q[rear++]={nx,ny};
            }
        }
    }
}
void move(){
    bool flag=true;
    int m=0;
    while(flag){
        m++;
        for(int i=0;i<sz;++i){
            if(a[cluster[i].x+m][cluster[i].y]=='x'){
               m-=1;
               flag=false;
               break; 
            }
        }
    }

    for(int i=0;i<sz;++i){
        a[cluster[i].x+m][cluster[i].y]='x';
    }
    sz=0;
}

int main()
{
    scanf("%d %d",&r,&c);
	for(int i=0;i<r;++i){
		scanf("%s",a+i);
	}
    /*임의로 땅만들기*/
    for(int i=0;i<c;++i){
        a[r][i]='x';
    }
    a[r][c]=0;

    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",h+i);
    }

    for(int t=0;t<n;++t){
        int x=r-h[t];
        int y;
        if(t&1){
            /*막대던지기*/
            for(y=c-1;y>=0;--y){
                if(a[x][y]=='x'){
                    a[x][y]='.';
                    break;
                }
            }
        }
        else{
            /*막대던지기*/
            for(y=0;y<c;++y){
                if(a[x][y]=='x'){
                    a[x][y]='.';
                    break;
                }
            }
        }
        bfs(r,0);   //땅에 붙어있는 클러스터 검사

        /*공중에 떠있는 클러스터 좌표저장*/   
        sz=0;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(a[i][j]=='x'&&!visited[i][j]){
                    cluster[sz++]={i,j};
                    a[i][j]='.';
                }
            }
        }
        if(sz) move();    
    }
    
    for(int i=0;i<r;++i){
        printf("%s\n",a[i]);
    }
    
    return 0;
}