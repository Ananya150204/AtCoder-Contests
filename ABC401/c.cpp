#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
void ak(){
    ll n,k;
    cin >> n >> k;
    vector<ll> arr(n+1,1);
    ll s = k;

    for (ll i = k; i <= n; i++){
        arr[i] = s;
        s = (s- arr[i-k]+(ll)1e9)%(ll)1e9;
        s = (s + arr[i]+(ll)1e9)%1000000000;
    }
    //curr = temp;
    cout << (arr[n]+(ll)1e9)%(ll)1e9 << endl;
    //cout << (433494437+701408733)%(ll)1e9 << endl;
}
int32_t main(){
    int t = 1;
    //cin >> t;
    while (t--){
        ak();
    }
}
