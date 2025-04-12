#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ak(){
    ll r;
    cin >> r;
    // (2*x+1)**2 + (2*y+1)**2 <= 4*r*r

    ll res = 1+ 4*(r-1);
    ll top = r-1;
    ll cnt = 0;
    // With x < r condition top can become negative as well
    for (ll x = 1; (2*x+1)*(2*x+1) + (2*1+1)*(2*1+1) <= 4*r*r; x++){
        while ((2*x+1)*(2*x+1) + (2*top+1)*(2*top+1) > 4*r*r){
            top--; 
        }
        cnt += max(top,0ll);
    }
    cnt = cnt*4;
    cout << res+ cnt << endl;
}
int32_t main(){
    int t = 1;
    //cin >> t;
    while (t--){
        ak();
    }
}