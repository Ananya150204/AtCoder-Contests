#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,pair<int,char>>> xyc;
    // unordered_map<int,int> xcw;
    // unordered_map<int,int> xcb;
    // unordered_map<int,int> ycw;
    // unordered_map<int,int> ycb;
    for (int i = 0; i < m; i++){
        int x,y;
        char c;
        cin >> x >> y >> c;
        xyc.push_back({x,{y,c}});
    }
    sort(xyc.begin(),xyc.end());

    bool flag = true;
    int miny = INT_MAX;
    for (int i = 0; i < xyc.size(); i++){
        int y = xyc[i].second.first;
        char c = xyc[i].second.second;

        if (c == 'W'){
            miny = min(y,miny);
        }
        else {
            if (y >= miny){
                flag = false;
                break;
            }
        }
    }
    if (flag){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

}