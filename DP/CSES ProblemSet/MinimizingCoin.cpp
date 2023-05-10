#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,s;  cin >> n >> s;
    ll coins[n+1];
    for(ll i = 1; i <=n ;i++){
        cin >> coins[i];
    }
    vector<ll> dp(s+1);
    dp[0] = 0;
    for(ll i = 1; i <= s; i++){
        dp[i] = INT_MAX;
        for(ll x = 1; x <= n; x++){
            if(coins[x] <= i){
                dp[i] = min(dp[i],1+dp[i-coins[x]]);
            } 
        }
    }
    // for(int i = 0; i <= s;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    int ans = (dp[s] == INT_MAX) ? -1 : dp[s];
    cout<<ans;
    return 0;
}