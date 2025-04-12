#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool chk(int i, int j, vector<vector<char>>& s, vector<vector<char>>& t){
    int m = t.size();
    for (int k = i; k < i+m; k++){
        for (int l = j; l < j+m; l++){
            if (s[k][l] != t[k-i][l-j]){
                return false;
            }
        }
    }
    return true;
}
void ak(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> s(n,vector<char>(n));
    vector<vector<char>> t(m,vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            cin >> t[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (chk(i,j,s,t)){
                cout << i+1 << " " << j+1 << endl;
                return;
            }
        }
    }
}
int32_t main(){
    int t = 1;
    //cin >> t;
    while (t--){
        ak();
    }
}
