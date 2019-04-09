#include <bits/stdc++.h>
using namespace std;
#define SAFE(x,y)   (x)<11&&(y)<11
typedef pair<int,int> point;
const int INF = 0x3f3f3f3f;
int a[11][11];
int psum[11][11];
int total[6]={0,5,5,5,5,5};
vector<point> v;
bool visited[11][11];

int ans=INF;

int max_square_size(int row, int col){
    /*구간합이 넓이와 같으면 색종이를 붙일 수 있음*/
    int size=5;
    while(size){
        if(SAFE(row+size-1,col+size-1)){
            if(psum[row + size - 1][col + size - 1] - psum[row - 1][col + size - 1] - psum[row + size - 1][col - 1] + psum[row - 1][col - 1] == size * size){
                return size;
            }
        }
        size--;
    }
}

bool iscovered(int row, int col, int size){
    /*색종이를 붙이려는 범위내에 이미 색종이가 있는지 검사하는 함수*/
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            if(visited[i+row][j+col]) return true;
        }
    }
    return false;
}

void cover(int row, int col, int size){
    /*색종이를 붙이는 함수*/
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            visited[i+row][j+col] = true;
        }
    }
}

void uncover(int row, int col, int size){
    /*색종이를 제거하는 함수(백트래킹)*/
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            visited[i+row][j+col] = false;
        }
    }
}

void dfs(int idx,int cnt){
    if(idx==v.size()){
        ans=min(ans,cnt);
        return;
    }

    if(cnt>ans) return;         //진행도중 최소값보다 커졌으면 return <-- 이거 없으면 시간 좀 오래걸림

    int x=v[idx].first;
    int y=v[idx].second;
    
    if(visited[x][y]){      //이미 붙었으면 다음걸로 이동
        dfs(idx+1,cnt);
        return;
    }
    
    int sz=max_square_size(x,y);    //가능한 최대 사이즈 구하기

    for(int i=sz;i>=1;--i){         //최대 사이즈 부터 하나씩 줄여가며 진행
        if(total[i]&&!iscovered(x,y,i)){    //사용할 색종이가 남아있으면서 아직 안덮여있으면 진행
             total[i]--;
             cover(x,y,i);
             dfs(idx+1,cnt+1);
             uncover(x,y,i);
             total[i]++;
        }
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //psum을 이용해서 사각형을 판단할 예정
    
    for (int i = 1; i <= 10; ++i){
        for (int j = 1; j <= 10; ++j){
            cin >> a[i][j];
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + a[i][j];    //사각형의 크기를 판단하기 위한 psum
            if(a[i][j]) v.emplace_back(i,j);    //값이 1인 좌표들로부터 색종이를 붙일 수 있는지 완탐을 할 예정
        }
    }

    dfs(0,0);

    if(ans==INF){
        cout<<-1;
    }
    else{
        cout<<ans;
    }

    return 0;
}