#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
        int top =  0, bottom = n - 1, left = 0, right = n - 1;
        vector<vector<int> > spiralMatrix(n,vector<int>(n));
        int dir = 0;
        int idx;
        int val = 1;
        while(top <= bottom && left <= right){
            if(dir == 0){
                idx = left;
                while(idx <= right){
                    spiralMatrix[top][idx++] = val++;
                }
                top++;
                dir = 1;
            }
            if(dir == 1){
                idx = top;
                while(idx <= bottom){
                    spiralMatrix[idx++][right] = val++;
                }
                right--;
                dir = 2;
            }
            if(dir == 2){
                idx = right;
                while(idx >= left){
                    spiralMatrix[bottom][idx--] = val++;
                }
                bottom--;
                dir = 3;
            }
            if(dir == 3){
                idx = bottom;
                while(idx >= top){
                    spiralMatrix[idx--][left] = val++;
                }
                left++;
                dir = 0;
            }
        }
        return spiralMatrix;
    }

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif  
    int n;  cin >> n;
    vector<vector<int> > spiralMatrix = generateMatrix(n);
    for(int i= 0; i < n; i++){
        for(int j = 0; j  < n; j++){
            cout<<spiralMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

