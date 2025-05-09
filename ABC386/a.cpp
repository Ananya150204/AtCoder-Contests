#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    unordered_map<int,int> mpp;
    mpp[a] += 1;
    mpp[b] += 1;
    mpp[c] += 1;
    mpp[d] += 1;

    if (mpp.size() == 2){
        unordered_set<int> st;
        for (auto& it : mpp){
            st.insert(it.second);
        }
        if (st.find(2) != st.end()){
            cout << "Yes" << endl;
        }
        else if (st.find(1) != st.end()){
            cout << "Yes" << endl;
        }
        else if (st.find(3) != st.end()){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else{
            cout << "No" << endl;
        }
}