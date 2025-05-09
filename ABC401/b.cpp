#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ak(){
    int n;
    cin >> n;
    string s;
    bool logOut = true;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> s;
        if (s == "login"){
            logOut = false;
        }
        else if (s == "logout"){
            logOut = true;
        }
        else if (s == "private"){
            if (logOut){
                cnt ++;
            }
        }
    }
    cout << cnt << endl;

}
int32_t main(){
    int t = 1;
    //cin >> t;
    while (t--){
        ak();
    }
}
