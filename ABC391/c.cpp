#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ak(){
    int n;
    cin >> n;
    vector<int>v(n,1); // How many in each nest
    int cnt = 0;
    unordered_map <int,int> locp; // Location of each pigeon
    for (int i = 0; i < n; i++){
        locp[i] = i;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int num;
        cin >> num;
        if (num == 2){
            cout << cnt << endl;
        }
        else {
            int p,h;
            cin >> p >> h;
            p--;h--;
            int hn = locp[p];
            if (v[hn] > 1 && v[hn]-1 <= 1){
                cnt--;
            }
            if (v[h] == 1){
                cnt++;
            }
            v[hn]--; v[h]++;
            locp[p] = h;
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
