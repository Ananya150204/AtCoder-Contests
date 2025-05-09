#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ak(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t = s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '?'){
            if ((i >= 1 && s[i-1] == 'o') || (i+1 < s.size() && s[i+1] == 'o')){
                t[i] = '.';
            }
        }
    }
    int fixed_o = count(t.begin(),t.end(),'o');
    if (fixed_o == k){
        cout << t << endl;
        return;
    }

    string greedy = t;
    int max_o = fixed_o;
    for (int i = 0; i < s.size(); i++){
        if (t[i] == '?'){
            if ((i >= 1 && t[i-1] == 'o') || (i+1 < s.size() && t[i+1] == 'o')){
                greedy[i] = '.';
            }
            else {
                greedy[i] = 'o';
                max_o ++;
            }
        }
    }
    if (max_o < k){
        // Impossible
        cout << s << endl;
        return;
    }
    if (max_o == k){
        cout << greedy << endl;
        return;
    }

    if (max_o > k){
        string alt1 = greedy;
        string alt2 = greedy;
        // Note that u will not 
        for (int i = 0; i < s.size();){
            if (t[i] != '?'){
                i++;
                continue;
            }
            int j = i;
            while (j < s.size() && t[j] == '?'){
                j++;
            }
            int len = j-i;

            for (int x = 0; x < len; x++){
                alt1[i+x] = (x%2==0)?'.':'o';
                alt2[i+x] = (x%2==1)?'.':'o';
            }
            i = j;
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
