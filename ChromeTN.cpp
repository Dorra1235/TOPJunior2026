#include <bits/stdc++.h>
#define int long long
#define ll __int128
#define fi first 
#define se second
using namespace std;
//YOU CAN MAKE IT
//go go optimize !!
int m,k;
bool good(int num){
    ll each=num/k;
    ll miss =num%k;
    ll check;
    check =(((each)*((each+1)))/2)*k;
    if (check>m)return false;
    check += miss*(each+1);
    return check<=m;
}
void solve(){
    //bs
    cin>>m>>k;
    int l = 0;
    int r = 1e18;
    int ans = -1;
    if (m<k){
        cout<<m<<"\n";
        return;
    }
    while (l<=r){
        int  mid = l+(r-l)/2;
        if (good(mid)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        } 
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while (t--)solve();
    return 0;
}