#include <bits/stdc++.h>
using namespace std;

int main(){
    long n,r;
    cin >> n >>r;
    for (long i =0; i < n; i++){
        int div; int del;
        cin >> div >> del;
        if (div == 1 && r >= 1600 && r <= 2799){
            r = r + del;
        }
        else if (div == 2 && r >= 1200 && r <= 2399){
            r = r + del;
        }
    }
    cout << r << endl;
}