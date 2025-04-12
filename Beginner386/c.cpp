#include <bits/stdc++.h>
using namespace std;

#define int  long unsigned int
// What I missed was that I might have to insert the character at the very end which
// will not be captured by the loop.
int32_t main(){
    int k;
    string s,t;
    cin >> k >> s >> t;
    if (s == t){
        cout << "Yes" << endl;
    }
    else {
        if (s.size() == t.size()){
            bool can = true;
            int cnt = 0;
            for (int i = 0; i < (int)s.size(); i++){
                if (s[i] != t[i]){
                    cnt ++;
                    if (cnt >= 2){
                        can = false;
                        break;
                    }
                }
            }
            if (can){
                cout << "Yes" << endl;
            }
            else {
                //cout << 1 << endl;
                cout << "No" << endl;
            }
        }
        else if (s.size()-t.size() == 1){
            bool done = false;
            for (int i = 0; i < (int)t.size(); i++){
                if (s[i] != t[i]){
                    done = true;
                    s.erase(s.begin()+i);
                    break;
                }
            }
            if (!done){ // U haven't done any insertion so do it now.
                cout << "Yes" << endl;
            }
            else if (s == t){
                cout << "Yes" << endl;
            }
            else {
                //cout << 3 << endl;
                cout << "No" << endl;
            }
        }
        else if (t.size()-s.size() == 1) {
            bool done = false;
            for (int i = 0; i < (int)s.size(); i++){
                if (s[i] != t[i]){
                    done = true;
                    s.insert(s.begin()+i,1,t[i]);
                    break;
                }
            }
            //cout << s << " " << t << endl;
            if (!done){
                cout << "Yes" << endl;
            }
            else if (s == t){
                cout << "Yes" << endl;
            }
            else {
                //cout << 4 << endl;
                cout << "No" << endl;
            }
        }
        else if (s.size()-t.size() >= 2 || t.size()-s.size() >= 2){
            //cout << s.size() << " " << t.size() << endl;
            cout << "No" << endl;
        }
    }
    
}