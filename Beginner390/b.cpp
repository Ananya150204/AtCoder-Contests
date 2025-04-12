#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ak(){
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if (a[1] == a[0]){
        if (sum == n*a[0]){
            cout << "Yes" << endl;
            return;
        }
        else {
            cout << "No" << endl;
            return;
        }
    }
    double r = 1.0*a[1]/a[0];
    double temp = 1;
    for (int i = 0; i < n; i++){
        temp *= r; 
    }
    double s = 1.0*a[0]*(temp-1)/(r-1);
    if (round(s) == sum){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }  
}
int32_t main(){
    int t = 1;
    //cin >> t;
    while (t--){
        ak();
    }
}
