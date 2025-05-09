#include<bits/stdc++.h>
using namespace std;
#define ll long long
// Where we primarily lacked :
// 1. k-th element in deque can be accessed in O(1)
// 2. Storing offset saves redundant computation.
// 3. Store a snake by a tuple, not just by its length.
void ak(){
    int q;
    cin >> q;
    deque<pair<ll,ll>> snakes; // Head coordinate, length
    long offset = 0; // Stores the cumulative shift in position of snakes
    // as they leave
    for (int i = 0; i < q; i++){
        int num;
        cin >> num;
        if (num == 1){
            ll l;
            cin >> l;
            if (snakes.empty()){
                snakes.push_back({0,l});
            }
            else {
                ll last_head = snakes.back().first;
                ll last_len = snakes.back().second;
                snakes.push_back({last_head+last_len, l});
            }
        }
        else if (num == 2){
            ll first_len = snakes.front().second;
            offset += first_len;
            snakes.pop_front();
        }
        else {
            ll k;
            cin >> k;
            ll k_head = snakes[k-1].first;
            // But the offset must be subtracted
            k_head -= offset;
            cout << k_head << endl;
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