#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define ff first
#define sc second

struct contributor{
    string name; int n;
    vector<pair<string, int>> skills;
};

struct project{
    string name;
    int d,s,b,r;
    vector<pair<string, int>> roles;
};

bool cmp(project x, project y){
    
    return x.s<y.s;
}

bool cmp2(pii x, pii y){
    return x.sc<y.sc;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << "Enter input/output file name" << endl;
    char in[100], out[100];
    // Input file names
    scanf("%s",in); scanf("%s", out);
    FILE *inp = freopen("input.txt", "r", stdin);
    
    map<string, int> skillencoder;
    map<int, string> skilldecoder;
    // skills -> pair<developer, int>
    map<int, vector<pii>> dev;
    int C,P; cin >> C >> P;
    vector<contributor> con(C); 
    vector<project> pro(P);
    int sk = 0;
    // Read contributor
    for(int i=0; i<C; i++){
        cin >> con[i].name;
        cin >> con[i].n;
        for(int j=0; j<con[i].n; j++){
            con[i].skills.emplace_back();
            cin >> con[i].skills[j].ff >> con[i].skills[j].sc;
            if(skillencoder.find(con[i].skills[j].ff)!=skillencoder.end()){
                dev[skillencoder[con[i].skills[j].ff]].push_back({i, con[i].skills[j].sc});
            }
            else{
                skillencoder[con[i].skills[j].ff] = sk++;
                dev[skillencoder[con[i].skills[j].ff]].push_back({i, con[i].skills[j].sc});
            }
        }        
    }
    // for(auto x:skillencoder){
    //     cout << x.ff << " " << x.sc  << endl;
    // }
    // for(auto x:dev){
    //     cout << x.ff << endl;
    //     for(auto y:x.sc){
    //         cout << y.ff << " " << y.sc << endl;
    //     }
    // }
    // Read project
    for(int i=0; i<P; i++){
        cin >> pro[i].name;
        cin >> pro[i].d >> pro[i].s >> pro[i].b >> pro[i].r;
        for(int j=0; j<pro[i].r; j++){
            pro[i].roles.emplace_back();
            cin >> pro[i].roles[j].ff >> pro[i].roles[j].sc;
        }        
    }
    int pk = 0;
    sort(pro.begin(), pro.end(), cmp);
    vector<vector<int>> assigned(P);
    vector<bool> visited(C,false);
    vector<bool> vis(P,false);
    int currday = 0;
    hell:;
    for(int i=0; i<P; i++){
        if(vis[i]){
            continue;
        }
        // cout << i << endl;
        for(auto x:pro[i].roles){
            if(skillencoder.find(x.ff)==skillencoder.end()){
                break;
            }
            else{
                bool f=false;
                for(int j=0; j<dev[skillencoder[x.ff]].size(); j++){
                    if(skillencoder.find(x.ff)==skillencoder.end()){
                        vis[i] = true;
                        break;
                    }
                    if(!visited[dev[skillencoder[x.ff]][j].ff] && dev[skillencoder[x.ff]][j].sc>=x.sc){
                        // cout << x.ff  << " " << dev[skillencoder[x.ff]][j].ff << " " << dev[skillencoder[x.ff]][j].ff << endl;
                        assigned[i].push_back(dev[skillencoder[x.ff]][j].ff);
                        visited[dev[skillencoder[x.ff]][j].ff] = true;
                        break;
                    }
                }
            }
        }
    }
    int cnt=0;
    for(int i=0; i<P; i++){
        if(assigned[i].size()==pro[i].r){
            currday+=pro[i].d;
            vis[i] = true;
            cnt++;
            for(int j=0; j<pro[i].r; j++){
                string s = pro[i].roles[j].ff;
                for(int t=0; t<dev[skillencoder[s]].size(); t++){
                    if(dev[skillencoder[s]][t].first==assigned[i][j]){
                        dev[skillencoder[s]][t].sc+=1;
                        break;
                    }
                }
            }
        }
    }
    if(pk<50){
        pk++;
        goto hell;
    }
    FILE *opt = freopen("output.txt", "w", stdout);
    cout << cnt << endl;
    for(int i=0; i<P; i++){
        if(assigned[i].size()==pro[i].r){
            cout << pro[i].name << endl;
            for(int j=0; j<pro[i].r; j++){
                cout << con[assigned[i][j]].name << " "; 
            }
            cout << endl;
        }
    }
    fclose(opt);
    return 0;
}