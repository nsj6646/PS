#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[1001];
int ans[1001];

int n;
bool cmp(const pair<int,int> &u,const pair<int,int> &v){
    if(u.second==v.second){
        return u.first<v.first;
    }
    return u.second>v.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n,cmp);

    for(int i=0;i<n;++i){
        for(int j=a[i].first;j>=1;--j){
            if(!ans[j]){
                ans[j]=a[i].second;
                break;
            }
        }
    }
    int sum=0;
    for(int i=1;i<=1000;++i){
        sum+=ans[i];
    }
    cout<<sum;
    return 0;
}