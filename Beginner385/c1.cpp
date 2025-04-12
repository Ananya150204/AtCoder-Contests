#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++){
        cin >> height[i];
    }
    int ans = 1;
    for (int k = 1; k <= n; k++){
        for (int i = 0; i < k; i++){ // k groups
            int j = i;
            int lmax = 0;
            int curr = 0;
            int high = -1;
            while (j < n){
                if (high != height[j]){
                    lmax = max(curr,lmax);
                    curr = 0;
                    high = height[j];
                }
                curr += 1;
                ans = max(ans,curr);
                ans = max(ans,lmax);
                j = j+k;
            }
            ans = max(ans,lmax);
            ans = max(ans,curr);
        }
    }
    cout << ans << endl;
}
int32_t main(){
    int t = 1;
    while (t--){
        solve();
    }
}