#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ak(){
    ll x;
    cin >> x;
    ll prod = 1;
    for (int i = 1; i <= x; i++){
        prod = prod*i;
        if (prod == x){
            cout << i << endl;
            return;
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