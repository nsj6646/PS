#include <bits/stdc++.h>
using namespace std;
#define N   500001

int a,b;
int visited[N];
int t=1;
queue<int> q;
bool safe(int x){
    return x>=0&&x<N;
}
int main(void) {
    cin>>a>>b;

    if(a==b){
        cout<<0;
        return 0;
    }
    q.push(a);
    visited[a]=0;
    while(!q.empty()){
        b+=t;
        if(b>=N){
            break;
        }
        int sz=q.size();
        while(sz--){
            int x=q.front();
            q.pop();
            int nx;
            nx=x-1;
            if(safe(nx)&&visited[nx]!=t){
                if(nx==b){
                    cout<<t;
                    return 0;
                }
                q.push(nx);
                visited[nx]=t;
            }
            nx=x+1;
            if(safe(nx)&&visited[nx]!=t){
                if(nx==b){
                    cout<<t;
                    return 0;
                }
                q.push(nx);
                visited[nx]=t;
            }
            nx=x*2;
            if(safe(nx)&&visited[nx]!=t){
                if(nx==b){
                    cout<<t;
                    return 0;
                }
                q.push(nx);
                visited[nx]=t;
            }
        }
        t++;
    }
    cout<<-1;
    return 0;
}