#include<bits/stdc++.h>
using namespace std;
#define ll long long

// U knew that u had to cout an ans which was the result of mins of many
// computes. In such cases always remember to keep the func type void, compare
// when destination reached & keep a store of the val to be computed.
ll ans = 1ll << 60;
void dfs(vector<vector<ll>>& adj_mat, ll sv,vector<bool>& isVis, ll x){
    ll n = adj_mat.size();
    if (sv == n-1){
        ans = min(ans,x);
    }

    isVis[sv] = true;
    vector<ll> adj = adj_mat[sv];

    for (ll i = 0; i < n; i++){
        if (adj[i] >= 0 && !isVis[i]){
            // If vertex is unvisited, advance to vertex
            dfs(adj_mat,i,isVis,x^adj[i]);
        }
    }
    isVis[sv] = false;
}
void ak(){
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> adj_mat(n,vector<ll>(n,-1));
    for (ll i = 0; i < m; i++){
        ll f,s,w;
        cin >> f >> s >> w;
        adj_mat[f-1][s-1] = w;
        adj_mat[s-1][f-1] = w;
    }
    vector<bool> isVis(n,false);
    dfs(adj_mat,0,isVis,0ll);
    cout << ans << endl;
}
int32_t main(){
    int t = 1;
    //cin >> t;
    while (t--){
        ak();
    }
}
