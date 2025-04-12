#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6'|| 
        s[i] == '7' || s[i] == '8' || s[i] == '9'){
            cnt++;
        }
        else{
            if (i < n-1){
                if (s[i+1] == '0'){
                    cnt ++;
                    i++;
                }
                else {
                    cnt++;
                }
            }
            else {
                cnt ++;
            }
        }
    }
    cout <<cnt << endl;
}