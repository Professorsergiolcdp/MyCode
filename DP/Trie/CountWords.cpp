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
 
struct Node{
    Node* children[26];
    int Count_Prefix = 0;
    int ew = 0;
    
    bool containsKey(char ch){
        return children[ch-'a'] != NULL;
    }

    void put(char ch,Node* node){
        children[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return children[ch - 'a'];
    }
   
    void increasePrefix(){
        Count_Prefix++;
    }

   void increaseEndsWith(){
       ew++;
   }

   void DeleteEndsWith(){
       ew--;
   }

   void DeletePrefix(){
       Count_Prefix--;
   }

   int getEnd(){
       return ew;
   }

   int getPrefix(){
       return Count_Prefix;
   }
};

struct Trie{
    private: Node* root;
    public:

        Trie(){
            root = new Node();
        }


        void Insert(string s){
            Node* node = root;
            for(int i = 0;i < s.size(); i++){
                if(!node->containsKey(s[i])){
                    node->put(s[i],new Node());  
                }
                node = node->get(s[i]);
                node->increasePrefix();
            }
            node->increaseEndsWith();
        }

        int CountNumberOf(string s){
            Node *node = root;
            for(int i = 0;i < s.size();i++){
                if(!node->containsKey(s[i])){
                    return 0;
                }
                node = node->get(s[i]);
            }
            return node->getEnd();           
        }

        int CountNumberStartWith(string s){
            Node* node = root;
            for(int i = 0;i < s.size();i++){
                if(!node->containsKey(s[i])){
                    return 0;
                }
                node = node->get(s[i]);
            }
            return node->getPrefix();
        }

        void DeleteString(string s){
            Node* node = root;
            for(int i = 0;i < s.size();i++){
                if(node->containsKey(s[i])){
                    node = node->get(s[i]);
                    node->DeletePrefix();
                }else{
                    return;
                }
            }
            node->DeleteEndsWith();
        }
};

int main()
{
 Trie t;
 t.Insert("apple");
 t.Insert("apple");
 t.Insert("bat");
 t.Insert("apps");
 t.Insert("ape");
 cout<<t.CountNumberOf("apple")<<endl;
 t.DeleteString("apps");
 cout<<t.CountNumberStartWith("ap");
 return 0;
}