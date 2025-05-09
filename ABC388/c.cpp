#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // b >= 2*a
    int cnt = 0;
    for (int i = 0; i < n; i++){
        int start = i+1;
        int end = n-1;
        int mid = start + (end-start)/2;
        int ans = -1;
        while (start <= end){
            mid = start + (end-start)/2;
            if (arr[mid] >= 2*arr[i]){
                ans = mid;
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
        if (ans != -1){
            cnt = cnt + n-ans;
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