#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 


int main()
{
 #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
ll n;   cin >> n;
v64 v(n);

forn(i,n)   {
    cin >> v[i];
}

/*

ll sum = 0,ssum = 0;
forn(i,n){
        sum += v[i];
        ssum += (v[i]*v[i]);
}

ll nsum = (n*(n+1))/2;
ll nssum = (n*(n+1)*(2*n+1))/6;

ll rs_s = nsum - sum;
ll rss = nssum - ssum;
ll rs_a = rss/rs_s;
ll x = (rs_s+rs_a)/2;
ll y = (x - rs_s);
cout<<x<<" "<<y<<endl;

*/


ll xor_v = v[0];
for(ll i = 1;i < n ;i++)   xor_v ^= v[i];
ll xor_n = 1;
for(ll i = 2;i <= n;i++){
    xor_n ^= i;
}

ll xXORy = xor_v ^ xor_n;

// right most set bit
ll set_bit_no = (xXORy) & ~(xXORy - 1);

ll x = 0, y = 0;
for(ll i = 0;i < n ; i++){
    if(v[i] & set_bit_no){
        x ^= v[i];
    }else{
        y ^= v[i];
    }
}

for(ll i = 1; i <= n; i++){
    if(i & set_bit_no)  x^=i;
    else    y^=i;
}

cout<<x<<" "<<y<<endl;
// sort the array   O(nlogn)
// store the value in the map T - O(nlogn) S - O(n)
// insertion in map takes O(logn)


return 0;
}