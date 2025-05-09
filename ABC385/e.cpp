#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;
    vector<vector<int>> tree(n+1);
    vector<int> deg(n+1);
    for (int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        deg[u] += 1;
        deg[v] += 1;
    }
    int ans = n;
    // try x = 1..deg[u], picking the x-th neighbor's degree
    for (int i = 1; i <= n; i++){ // consider each node as center
        vector<int> adj = tree[i];
        sort(adj.begin(),adj.end(),[&](int a, int b){
            return deg[a] > deg[b];
        });
        int x = 0;
        int y = 0;
        for (int i = 0; i < adj.size(); i++){
            x += 1;
            y = deg[adj[i]]-1;
            ans = min(ans,(n-1-x-x*y));
        }
    }
    cout << ans << endl;
}