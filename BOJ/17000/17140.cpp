/*
 * boj 17140: 이차원 배열과 연산
 * copyright: nsj6646@naver.com
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE    101
int a[MAX_SIZE][MAX_SIZE];
int r,c,k;
int rSize,cSize;                        //현재 행과 열의 길이

set<int> s[MAX_SIZE];                   //[행or열]에 등장한 숫자들을 저장하는 set
int cnt[MAX_SIZE][MAX_SIZE];            //[행or열]에 [등장한 숫자]들의 count배열 
vector<pair<int,int>> v[MAX_SIZE];      //위 set과 배열을 토대로 <count, 숫자> 순으로 저장하여 정렬할 vector

/*
 * 정렬 rule
 * 1. 등장횟수가 커지는 순으로 => 등장 횟수가 작을수록
 * 2. 같으면 수가 커지는 순으로 => 수가 작은 순으로
 */

void r_sort(){
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=rSize;++i){
        s[i].clear();           //초기화
        for(int j=1;j<=cSize;++j){
            if(!a[i][j]) continue;  //0은 무시
            s[i].insert(a[i][j]);   //등장한 숫자 저장
            cnt[i][a[i][j]]++;      //등장한 횟수 저장
        }
    }
    int nSize=0;
    for(int i=1;i<=rSize;++i){
        v[i].clear();   //초기화
        for(int x:s[i]){    //set을 순회하며 등장한 숫자들 접근
            v[i].emplace_back(cnt[i][x],x);
        }
        nSize=max(nSize, (int)v[i].size());      //열의 길이를 새로하기 위해서 최대 길이 저장
    }
    
    cSize=nSize<<1;     //(숫자, 횟수)를 저장하기 때문에 길이*2
    for(int i=1;i<=rSize;++i){
        sort(v[i].begin(),v[i].end());  //정렬
        for(int j=0;j<v[i].size();++j){
            //배열에 저장
            a[i][2*j+1]=v[i][j].second;
            a[i][2*j+2]=v[i][j].first;
        }
        for(int j=v[i].size()*2+1;j<=cSize;++j){
            //빈공간은 0으로
            a[i][j]=0;
        }
    }
}
void c_sort(){
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=cSize;++i){
        s[i].clear();           //초기화
        for(int j=1;j<=rSize;++j){
            if(!a[j][i]) continue;  //0은 무시
            s[i].insert(a[j][i]);   //등장한 숫자 저장
            cnt[i][a[j][i]]++;      //등장한 횟수 저장
        }
    }
    int nSize=0;
    for(int i=1;i<=cSize;++i){
        v[i].clear();   //초기화
        for(int x:s[i]){    //set을 순회하며 등장한 숫자들 접근
            v[i].emplace_back(cnt[i][x],x);
        }
        nSize=max(nSize, (int)v[i].size());     //행의 길이를 새로하기 위해서 최대 길이 저장
    }
    
    rSize=nSize<<1;     //(숫자, 횟수)를 저장하기 때문에 길이*2
    for(int i=1;i<=cSize;++i){
        sort(v[i].begin(),v[i].end());  //정렬
        for(int j=0;j<v[i].size();++j){
            //배열에 저장
            a[2*j+1][i]=v[i][j].second;
            a[2*j+2][i]=v[i][j].first;
        }
        for(int j=v[i].size()*2+1;j<=rSize;++j){
            //빈공간은 0으로
            a[j][i]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>r>>c>>k;

    for(int i=1;i<=3;++i){
        for(int j=1;j<=3;++j){
            cin>>a[i][j];
        }
    }
    rSize=cSize=3;
    int ans=0;

    while(ans<=100 && a[r][c]!=k){
        /*solve*/
        if(rSize>=cSize){
            r_sort();
        }
        else{
            c_sort();
        }
        ans++;
    }


    if(ans>100){
        cout<<-1;
    }
    else{
        cout<<ans;
    }

    return 0;
}