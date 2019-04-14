/*
 * boj 17141: 연구소 2
 * copyright: nsj6646@naver.com
 */

#include <bits/stdc++.h>
using namespace std;
#define N       50
#define SAFE(x,y)   ((x)>=0&&(x)<n&&(y)>=0&&(y)<n)
typedef pair<int,int> point;

int a[N][N];
bool visited[N][N];
int n,m;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
vector<point> virus;        //바이러스를 놓을 수 있는 곳
vector<point> v;            //경우의 수(조합)를 위한 vector
queue<point> q;
int all;                    //모든 빈 칸
int ans=-1;

int bfs(){
    memset(visited,0,sizeof(visited));
    int timer=0;    //시간의 흐름
    int cnt=0;      //빈칸 채울때마다 증가해서 나중에 all과 비교

    for(int i=0;i<v.size();++i){
        q.push(v[i]);
        visited[v[i].first][v[i].second]=true;
        cnt++;
    }

    while(!q.empty()){
        timer++;
        int sz=q.size();
        while(sz--){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int k=0;k<4;++k){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(SAFE(nx,ny) && !visited[nx][ny] &&a[nx][ny]!=1){
                    cnt++;
                    visited[nx][ny]=true;
                    q.emplace(nx,ny);
                }
            }
        }
    }
    
    return cnt==all?timer-1:-1;
}

void dfs(int idx, int cnt){
    if(cnt==m){
        int res=bfs();
        if(res==-1) return;
        if(ans==-1||ans > res){
            ans=res;
        }
        return;
    }
    for(int i=idx;i<virus.size();++i){
        v.push_back(virus[i]);
        dfs(i+1,cnt+1);
        v.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>a[i][j];
            if(a[i][j]!=1) all++;
            if(a[i][j]==2) virus.emplace_back(i,j);
            
        }
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}