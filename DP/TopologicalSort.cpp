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


 vector<bool> visited(10000,false);

 stack<int> st;
void dfs(vector<int> adj[],int i){
    visited[i] = true;
    for(auto x: adj[i]){
        if(!visited[x]){
            dfs(adj,x);
        }
    }
    st.push(i);
}

 void dfsHelper(vector<int> adj[],int v){
     
     for(int i = 0; i < v; i++){
        if(!visited[i]){
            dfs(adj,i);
        }
     }
 }

void KahnAlgorithm(vector<int> adj[],int v){
        stack<int> s;
        queue<int> q;
        vector<int> indegree(v,0);
        for(int i = 0; i < v; i++){
            for(auto x: adj[i]){
                indegree[x]++;
            }
        }
        for(int i = 0; i < v;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for(auto x: adj[p]){
                indegree[x]--;
                if(indegree[x] == 0)   q.push(x);
            }
            s.push(p);
        }
        if(s.size() == v){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
}

int findPar(int node,vector<int> &rank,vector<int> &par){
    if(node == par[node]){
        return node;
    }
    return par[node] = findPar(par[node],rank,par);
}

void Union(int u,int v,vector<int> &rank,vector<int> &par){
    if(rank[u] == rank[v]){
        par[u] = v;
        rank[v]++;
    }
    else if(rank[u] > rank[v]){
        par[v] = u;
    }else{
        par[u] = v;
    }
    return;
}

void solve(){
    int v,e;    cin >> v >> e;
    vector<int> adj[v];
    vector<pair<int,int> > edges;
    for(int i = 0;i < e; i++){
        int a,b;    cin >> a >> b;
        edges.push_back({a,b});
        adj[a].push_back(b);
    }

    // this algorithm detects cycle in the graph

    // KahnAlgorithm(adj,v);

    vector<int> rank(v);
    vector<int> par(v);
    bool flag = true;
    for(int i = 0; i < v; i++){
        rank[i] = 0;
        par[i] = i;
    }
    for(auto x: edges){
        int sc = x.fi,  dest = x.se;
        if(findPar(sc,rank,par) != findPar(dest,rank,par)){
            Union(sc,dest,rank,par);
        }
        else{
            cout<<"This contains a punctured cycle"<<endl;
            flag = false;
            break;
        }
    }
    if(flag){
        cout<<"No cycle";
    }
    // dfsHelper(adj,v);
    // vector<int> ans;
    // while(!st.empty()){
    //     ans.push_back(st.top());
    //     st.pop();
    // }
    // for(auto x: ans)    cout<<x<<" ";

}

int main()
{
 #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
//  ll t;
//  cin >> t;
//  for(int it=1;it<=t;it++) {
      solve();
//  }
 return 0;
}