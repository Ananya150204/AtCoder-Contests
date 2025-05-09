#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ak(){
    int q;
    cin >> q;
    stack<int> s;
    for (int i = 0; i < 100; i++){
        s.push(0);
    }
    for (int i = 0; i < q; i++){
        int num;
        cin >> num;
        if (num == 1){
            int x;
            cin >> x;
            s.push(x);
        }
        else {
            cout << s.top() << endl;
            s.pop();
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
