#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,d;
    cin >> n >> d;
    vector<int> len(n);
    vector<int> th(n);
    for (int i = 0; i < n; i++){
        cin >> th[i] >> len[i];
    }
    for (int i = 1; i <= d; i++){
        int ans = INT_MIN;
        for (int j = 0; j < n; j++){
            ans = max(ans,(len[j]+i)*th[j]);
        }
        cout << ans << endl;
    }
}
int32_t main(){
    int t = 1;
    while (t--){
        solve();
    }
}
