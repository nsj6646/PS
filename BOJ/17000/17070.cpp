#include <bits/stdc++.h>
#define N 20
using namespace std;

struct pipe
{
    int x, y; //좌표
    int dir;  //방향
    pipe(int x, int y, int d) : x(x), y(y), dir(d) {}
};
int dx[] = {0, 1, 1}; //→, ↘, ↓
int dy[] = {1, 1, 0}; //→, ↘, ↓
int a[N][N];

int n;
bool safe(int x, int y, int dir)
{
    if (dir == 0){      //→
        return y <= n && !a[x][y];
    }
    else if (dir == 2){ //↓
        return x <= n && !a[x][y];
    }
    else{               //↘
        return x <= n && y <= n && !a[x][y] && !a[x - 1][y] && !a[x][y - 1];
    }
}
int ans;
void dfs(int x, int y, int dir)
{
    if (x == n && y == n){
        ans++;
        return;
    }

    for (int k = 0; k < 3; ++k)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (dir == 0 && k == 2 || dir == 2 && k == 0) continue; //가로->세로 or 세로->가로 안됌
        if (safe(nx, ny, k))
        {
            dfs(nx,ny,k);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    dfs(1, 2, 0);
    cout << ans;
    return 0;
}
/*bfs
#include <bits/stdc++.h>
#define N       20
using namespace std;

struct pipe{
    int x,y;        //좌표
    int dir;        //방향
    pipe(int x,int y,int d):x(x),y(y),dir(d){}
};
int dx[]={0,1,1};   //→, ↘, ↓
int dy[]={1,1,0};   //→, ↘, ↓
int a[N][N];

int n;
bool safe(int x,int y,int dir){
    if(dir==0){             //→
        return y<=n&&!a[x][y];
    }
    else if(dir==2){        //↓
        return x<=n&&!a[x][y];
    }
    else{                   //↘
        return x<=n&&y<=n&&!a[x][y]&&!a[x-1][y]&&!a[x][y-1];
    }
}
queue<pipe> q;
int ans;
void bfs(){
    q.push({1,2,0});
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int dir=q.front().dir;
        q.pop();

        if(x==n&&y==n){
            ans++;
            continue;
        }
        for(int k=0;k<3;++k){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(dir==0&&k==2||dir==2&&k==0) continue;    //가로->세로 or 세로->가로 안됌
            if(safe(nx,ny,k)){
                q.push({nx,ny,k});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }
    bfs();
    cout<<ans;
    return 0;
}
*/