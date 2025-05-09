#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; unsigned long s;
    cin >> n >> s;
    unsigned long sum = 0;
    vector <unsigned long> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    //cout << sum;
    if (s%sum == 0){
        cout << "Yes" << endl;
    }
    else {
        unsigned long rem = s%sum;
        vector<unsigned long> brr(2*n);
        for (int i = 0; i < n; i++){
            brr[i] = arr[i];
            brr[i+n] = arr[i];
        }
        // Calculate the set of prefix sums.
        unsigned long x = 0;
        set<unsigned long> prefix;
        for (int i = 0; i < 2*n; i++){
            x += brr[i];
            prefix.insert(x);
        }
        for (auto& it : prefix){
            if (prefix.find(it+rem) != prefix.end()){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }
}