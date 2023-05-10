#include<bits/stdc++.h>
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pll pair<ll,ll>
#define vll vector<ll, ll>
#define fori(n) for(ll i=0;i<n;i++)
#define range(a,b)  for(ll i=a;i<=b;i++)
using namespace std;

ll MOD = 1e9+7;



void solve(){
    int x,y; cin >> x >> y;
	vector<vector<int> >  v;

	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;   cin>>t;
    while(t--){
        solve();
    }
}