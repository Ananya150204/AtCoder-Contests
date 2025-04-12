#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ak(){
    int h,w;
    int xl = INT_MAX;
    int xr = INT_MIN;
    int yl = INT_MAX;
    int yr = INT_MIN;
    cin >> h >> w;
    vector<vector<char>> grid(h,vector<char>(w));
    for (int i = 0; i < h; i++){
        string s;
        cin >> s;
        for (int j = 0; j < w; j++){
            grid[i][j] = s[j];
            if (s[j] == '#'){
                xl = min(xl,i);
                xr = max(xr,i);
                yl = min(yl,j);
                yr = max(yr,j);
            }
        }
    }
    for (int i = xl; i <= xr; i++){
        for (int j = yl; j <= yr; j++){
            if (grid[i][j] == '.'){
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}
int32_t main(){
    int t = 1;
    //cin >> t;
    while (t--){
        ak();
    }
}
