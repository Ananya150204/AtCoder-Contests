#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ak(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n-2; i++){
        if (a[i] == a[i+1] && a[i+1] == a[i+2]){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}
int32_t main(){
    int t = 1;
    //cin >> t;
    while (t--){
        ak();
    }
}
