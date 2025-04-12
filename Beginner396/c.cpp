#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Never mix int & long
// Observe that u might need the maxi.
void ak(){
    int n,m;
    cin >> n >> m;
    vector <ll> b(n,0);
    vector <ll> w(m,0);
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    for (int i = 0; i < m; i++){
        cin >> w[i];
    }
    sort(b.rbegin(),b.rend());
    sort(w.rbegin(),w.rend());

    vector<ll> bs(n+1,0);
    vector<ll> ws(m+1,0); // This simply stores the prefix sums;
    // Store the max seen till now.
    vector<ll> maxws(m+1,0);
    
    for (int i = 1; i <= n; i++){
        bs[i] = bs[i-1] + b[i-1];
    }

    for (int i = 1; i <= m; i++){
        ws[i] = ws[i-1] + w[i-1];
        maxws[i] = max(maxws[i-1],ws[i]);
    }

    ll ans = 0;
    
    for (int i = 0; i <= n; i++){
        int idx = min(i,m);
        ans = max(ans,bs[i]+maxws[idx]);
    }
    cout << ans << endl;
}
int32_t main(){
    int t = 1;
    //cin >> t;
    while (t--){
        ak();
    }
}
