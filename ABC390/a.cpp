#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ak(){
    vector<int> arr (5);
    for (int i = 0; i < 5; i++){
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = 0; i < 4; i++){
        if (arr[i] > arr[i+1]){
            if (cnt == 0){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                cnt++;
            }
            else {
                break;
            }
            break;
        }
    }
    if (cnt == 0){
        cout << "No" << endl; return;
    }
    for (int i = 0; i < 5; i++){
        if (arr[i] != i+1){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
int32_t main(){
    int t = 1;
    //cin >> t;
    while (t--){
        ak();
    }
}
