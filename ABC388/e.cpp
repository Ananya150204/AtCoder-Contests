#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> vis(n,false);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // b >= 2*a
    int cnt = 0;
    int i = 0;
    int j = n/2; // U can't have more than n/2 pairs. So why not start from n/2 ?
    while (j < n){
        if (arr[j] >= 2*arr[i]){
            cnt++;
            i++;
            j++;
        }
        else {
            j++;
        }
    }
    cout << cnt << endl;
}
int32_t main(){
    int t = 1;
    while (t--){
        solve();
    }
}