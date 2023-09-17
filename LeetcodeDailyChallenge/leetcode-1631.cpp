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
 
/**
 * @brief : The minimum effort is the smallest difference between the adjacent heights
 * 
 */

bool isValid(int row,int col,int maxRows, int maxCol){
    return row >= 0 && row < maxRows && col >=0 && col < maxCol;
}


int minimumEffortPath(vector<vector<int>>& heights) {
    
    // Djistra Algorithm 
    int maxRows = heights.size();
    int maxCol = heights[0].size();
    vector<vector<int> > dist(maxRows,vector<int>(maxCol,INT_MAX));
    dist[0][0]= 0;
    priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>>, greater<tuple<int,int,int> > > pq;
    // {row,col, mininumEffortRequired}
    pq.push({0,0,0});

    while(!pq.empty()){
        tuple<int,int,int> tp = pq.top(); pq.pop();
        int effort = get<0>(tp);
        int x = get<1>(tp);
        int y = get<2>(tp);
        if(effort > dist[x][y]) continue;
        if(x == maxRows - 1 && y == maxCol - 1) return effort;
    
        int move_x[] = {-1,0,0,1};
        int move_y[] = {0,-1,1,0};
        for(int i = 0; i < 4; i++){
            int nr = x + move_x[i];
            int nc = y + move_y[i];
            if(isValid(nr, nc, maxRows,maxCol)){
                int newEffort = max(effort,abs(heights[nr][nc] - heights[x][y]));
                if(newEffort < dist[nr][nc]){
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort,nr,nc});
                }
            }
        }
    }
    return -1;
        
}

void solve(){
    vector<vector<int> > v;
    int n,m;    cin >> n >> m;
    for(int i = 0; i < n; i++){
        vector<int> temp;
        for(int j = 0; j < m; j++){
            int x;  cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }

    cout << minimumEffortPath(v);
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
      cout << "Case #" << it << ": ";
      solve();
 }
 return 0;
}