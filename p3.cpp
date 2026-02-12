#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
//go go optimize !!
const int MOD =1e9+7;
const int N = 1001;
void solve(){
    int n;cin>>n;
    vector<int>v(n);
    for (int j(0);j<n;j++)cin>>v[j];
    vector<vector<int>>dp(n,vector<int>(4,0));
    //last==0 means pref max
    //last==1 means pref min
    //last==2 means suf max
    //last==3 means suf min
    dp[0][0]=v[0];
    dp[0][1]=v[0];
    dp[n-1][2]=v[n-1];
    dp[n-1][3]=v[n-1];
    for (int j(1);j<n;j++){
        dp[j][0]=max(dp[j-1][0],v[j]);
        dp[j][1]=min(dp[j-1][1],v[j]);
    }
    for (int j(n-2);j>=0;j--){
        dp[j][2]=max(dp[j+1][2],v[j]);
        dp[j][3]=min(dp[j+1][3],v[j]);
    }
    int res = 0;
    for (int j(0);j<n-1;j++){
        res = max(res,min(dp[j][0]-dp[j][1],dp[j+1][2]-dp[j+1][3]));
    }
    cout<<res<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while (t--)solve();
    return 0;
}