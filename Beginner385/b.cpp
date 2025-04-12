#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,w,x,y;
    cin >> h >> w >> x >> y;
    vector<vector<char>> grid(h,vector<char>(w));
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cin >> grid[i][j];
        }
    }
    string t;
    cin >> t;
    set<pair<int,int>> st;
    x--; y--;
    for (int i = 0; i < t.size(); i++){
        if (t[i] == 'U' && grid[x-1][y] != '#'){
            if (grid[x][y] == '@'){
                //cout << x << " " << y << endl;
                st.insert({x,y});
            }
            x --;
        }
        else if (t[i] == 'D' && grid[x+1][y] != '#'){
            if (grid[x][y] == '@'){
                //cout << x << " " << y << endl;
                st.insert({x,y});
            }
            x ++;
        }
        else if (t[i] == 'L' && grid[x][y-1] != '#'){
            if (grid[x][y] == '@'){
                //cout << x << " " << y << endl;
                st.insert({x,y});
            }
            y --;
        }
        else if (t[i] == 'R' && grid[x][y+1] != '#'){
            if (grid[x][y] == '@'){
                //cout << x << " " << y << endl;
                st.insert({x,y});
            }
            y ++;
        }
    }
    if (grid[x][y] == '@'){
        //cout << x << " " << y << endl;
        st.insert({x,y});
    }
    cout << x +1 << " " <<  y+1 << " " << st.size() << endl;
}