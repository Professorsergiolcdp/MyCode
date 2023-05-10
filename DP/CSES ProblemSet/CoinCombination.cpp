#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll MOD = 1e9;
    ll n , target;  cin >> n >> target;
    vector<ll> coins(n);
    for(ll &x : coins)  cin >> x;
    ll dp[n+1][target+1];
    for(ll i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(ll i = 1; i <= target; i++){
        dp[0][i] = 0;
    }
    for(ll coin = 1; coin <= n ; coin++){
        for(ll sum = 1; sum <= target; sum++){
            dp[coin][sum] = dp[coin - 1][sum];
            ll left = sum - coins[coin - 1];
            if(left >= 0){
                dp[coin][sum] += dp[coin][left] %= MOD;
            } 

        }
    }
    cout<<dp[n][target];
    return 0;
}