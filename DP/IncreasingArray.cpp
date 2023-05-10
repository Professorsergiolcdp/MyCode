#include<bits/stdc++.h>
#define ll long long
using namespace std;
// llmax(lla,llb){
//     return a > b ? a : b;
// }
int main(){
    ll n;  cin >> n;
    vector<ll> v(n);
    for(ll i = 0;i < n; i++){
        cin >> v[i];
    }
    ll ans = 0,cnt = 0;
    for(ll i = 0;i < n; i++){
        cnt = max(v[i],cnt)*1ll;
        // cout<<cnt<<endl;
        ans+=(cnt-v[i]);
    }
    cout<<ans<<endl;
    return 0;
}