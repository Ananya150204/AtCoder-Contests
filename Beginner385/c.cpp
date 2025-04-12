#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    //vector<int> h(n);
    map<int,vector<int>> mpp;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        mpp[num].push_back(i);
    }
    int maxi = 1;
    for (auto &it : mpp){
        vector<int> build = it.second;
        map<int,int>diff;
        for (int i = 0; i < build.size(); i++){
            for (int j = i+1; j < build.size(); j++){
                diff[build[j]-build[i]] += 1;
                cout << build[j]-build[i] << " ";
            }
        }
        cout << endl;
        for (auto &itt : diff){
            maxi = max(maxi, itt.second);
        }
    }
    cout << maxi << endl;
}