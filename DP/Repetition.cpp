#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;   cin >> s;
    int ans = 0;
    int n = s.size();
    for(int i = 0; i < s.size(); i++){
        int cnt  = 1;
        while(i < n - 1 && s[i] == s[i+1]) {
            cnt++;
            i++;
        } 
        ans = max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}

