#include<bits/stdc++.h>
using namespace std;
int main(){
 #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;   cin >> s;
    map<char,int> m;
    int k = 0,ans = 0;
    for(int i = 0; i < s.size();i++){
       m[s[i]]++;   
       if(m[s[i]] > 1){
            int p = m.size();
            ans = max(ans,p);
            m.clear();
        }
    }
    cout<<ans<<endl;
}