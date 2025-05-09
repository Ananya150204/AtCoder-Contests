#include<bits/stdc++.h>
using namespace std;
#define ll long long
void calc(vector<int> a, string s, set<int> val){
    bool allZeros = true;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '1'){
            allZeros = false;
        }
    }
    if (allZeros){
        return;
    }
    sort(s.rbegin(),s.rend());
    int oi = -1;
    int zi = -1;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '1' && oi == -1){
            oi = i;
        }
        else if (s[i] == '0' && zi == -1){
            zi == i;
        }
    }
    if (zi == -1){
        zi = s.size();
    }
    for (int i = oi; i < zi; i++){
        for (int j = oi+1; j < zi; j++){
            a[i] = a[i]+a[j];
            s[j] = '0';
            int xor = c(a,oi,zi);
        }
    }
}
void ak(){
    int n;
    cin >> n;
    vector<int> a(n);
    string s = "";
    for (int i = 0; i < n; i++){
        cin >> a[i];
        s += '1';
    }
    set<int> val;
    calc(a,s,val);
    cout << s.size() <<endl;
}
int32_t main(){
    int t = 1;
    //cin >> t;
    while (t--){
        ak();
    }
}
