#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ak(){
    int n,w;
    cin >> n >> w;
    map<int,pair<int,int>> mpp;
    vector<priority_queue<pair<int,int>,vector<pair<int,int>>,std::greater<pair<int,int>>>> pq(w+1);
    for (int i = 1; i <= n; i++){
        int x,y;
        cin >> x >> y;
        //blks.push_back({{x,y},i});
        mpp[i] = {x,y};
        //blksx[x].push_back(i);
        pq[x].push({y,i});
    }
    vector<int> expt(n+1,INT_MAX);
    int t = 1;
    while (mpp.size() >= w){
        int maxi = INT_MIN;
        bool flag = false;
        vector<int> v;
        for (int i = 1; i <= n; i++){
            if (!pq[i].empty()){
                int num = pq[i].top().first; // Minimum y for each w
                int blk_ind = pq[i].top().second;
                v.push_back(blk_ind);
                maxi = max(maxi,num);
                pq[i].pop();
            }
            else {
                flag = true;
                break;
            }
        }
        if (flag){
            break;
        }
        for (int i = 0; i < v.size(); i++){
            expt[v[i]] = maxi;
            mpp.erase(v[i]);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int t;
        int b;
        cin >> t >> b;
        if (expt[b] == INT_MAX){
            cout << "Yes" << endl;
        }
        else if (expt[b] > t){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
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
