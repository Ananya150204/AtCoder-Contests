#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,m;
    int x,y;
    cin >> n >> m >> x >> y;
    set<pair<int,int>> houses;
    set<pair<int,int>> st;
    map<int,set<int>> xcc;
    map<int,set<int>> ycc;
    for (int i = 0; i < n; i++){
        int xc,yc;
        cin >> xc >> yc;
        xcc[xc].insert(yc);
        ycc[yc].insert(xc);
    }
    int ans = 0;
    for (int i = 0; i < m; i++){
        char d; int c;
        cin >> d >> c;
        if (d == 'U'){
            int newy = y+c;
            auto it = xcc[x].lower_bound(y);
            while (it != xcc[x].end() && *it <= newy){
                ans++;
                ycc[*it].erase(x); // At that (x,y) the house is already considered.
                it = xcc[x].erase(it); // Increase the iterator
            }
            y = newy;
        }
        else if (d == 'D'){
            int newy = y-c;
            auto it = xcc[x].lower_bound(newy);
            while (it != xcc[x].end() && *it <= y){
                ans ++;
                ycc[*it].erase(x);
                it = xcc[x].erase(it);
            }
            y = newy;
        }
        else if (d == 'L'){
            int newx = x-c;
            auto it = ycc[y].lower_bound(newx);
            while (it != ycc[y].end() && *it <= x){
                ans ++;
                xcc[*it].erase(y);
                it = ycc[y].erase(it);
            }
            x = newx;
        }
        else if (d == 'R'){
            int newx = x+c;
            auto it = ycc[y].lower_bound(x);
            while (it != ycc[y].end() && *it <= newx){
                ans ++;
                xcc[*it].erase(y);
                it = ycc[y].erase(it);
            }
            x = newx;
        }
    }
    cout << x << " " <<  y << " " << ans << endl;
}