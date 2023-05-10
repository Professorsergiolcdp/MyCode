#include<bits/stdc++.h>
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pll pair<ll,ll>
#define vll vector<ll>

#define fori(n) for(ll i=0;i<n;i++)
#define range(a,b)  for(ll i=a;i<=b;i++)
using namespace std;



void solve()
{

    ll n,q;  cin >> n >> q;
    vector<ll> arr(n);
    fori(n) cin >> arr[i];
    vector<ll> pre(n);
    pre[0] = arr[0];
    for(ll i = 1; i < n; i++)
    {
        pre[i] = pre[i-1] + arr[i];
    }
    fori(q)
    {
        ll ans = 0;
        ll a,b;    cin >> a >> b;
        if(a == 1)
        {
            ans = pre[b-1];
        }else{
            ans = pre[b-1] - pre[a-1 -1];
        }
        cout<<ans<<endl;
    }

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
   
        solve();
    
}

