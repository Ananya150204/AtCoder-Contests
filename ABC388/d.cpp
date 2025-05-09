#include <bits/stdc++.h>
using namespace std;
#define int long long
// https://chatgpt.com/c/678b6cd8-260c-8002-a553-7b8bff1523ba
void solve(){
    int n;
    cin >> n;
    vector<int> stones(n);
    for (int i = 0; i < n; i++){
        cin >> stones[i];
    }
    // obtained = stones + count
    vector<int> obtained(n);
    priority_queue<int,vector<int>,std::greater<int>> deactivation_times;
    for (int i = 0; i < n; i++){
        while (!deactivation_times.empty() && deactivation_times.top() <= i){
            deactivation_times.pop();
        }
        obtained[i] = stones[i]+(int)deactivation_times.size();
        deactivation_times.push((int)i+ obtained[i]+1);
    }
    
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        ans[i] = max(0ll,obtained[i]-n+i+1);
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
int32_t main(){
    int t = 1;
    while (t--){
        solve();
    }
}