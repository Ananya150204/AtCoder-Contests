#include <bits/stdc++.h>
using namespace std;

char toc (int a){
    if (a == 0){
        return 'A';
    }
    if (a == 1){
        return 'B';
    }
    if (a == 2){
        return 'C';
    }
    if (a == 3){
        return 'D';
    }
    return 'E';
}

int main(){
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;

// BC
// AC
// AB
// E
// D
// C
// B
// A
    vector <pair <long, string>> brr;
    brr.push_back({a+b+c+d+e, "ABCDE"});
    brr.push_back({b+c+d+e, "BCDE"});
    brr.push_back({a+c+d+e,"ACDE"});
    brr.push_back({a+b+d+e,"ABDE"});
    brr.push_back({a+b+c+e, "ABCE"});
    brr.push_back({a+b+c+d, "ABCD"});
    brr.push_back({c+d+e, "CDE"});
    brr.push_back({b+d+e, "BDE"});
    brr.push_back({a+d+e, "ADE"});
    brr.push_back({b+c+e, "BCE"});
    brr.push_back({a+c+e, "ACE"});
    brr.push_back({b+c+d, "BCD"});
    brr.push_back({a+b+e, "ABE"});
    brr.push_back({a+c+d, "ACD"});
    brr.push_back({a+b+d, "ABD"});
    brr.push_back({a+b+c, "ABC"});
    brr.push_back({d+e, "DE"});
    brr.push_back({c+e, "CE"});
    brr.push_back({b+e, "BE"});
    brr.push_back({c+d, "CD"});
    brr.push_back({a+e, "AE"});
    brr.push_back({b+d, "BD"});
    brr.push_back({a+d, "AD"});
    brr.push_back({b+c, "BC"});
    brr.push_back({a+c, "AC"});
    brr.push_back({a+b, "AB"});
    brr.push_back({e, "E"});
    brr.push_back({d, "D"});
    brr.push_back({c, "C"});
    brr.push_back({b, "B"});
    brr.push_back({a, "A"});
     auto comparator = [](const pair<long, string>& a, const pair<long, string>& b) {
        if (a.first != b.first) 
            return a.first > b.first; // Decreasing order of long
        return a.second < b.second; // Increasing order of first char
    };
    sort(brr.begin(),brr.end(), comparator);
    for (int i = 0; i < brr.size(); i++){
        //string crr = brr[i].second;
        cout << brr[i].second;
        cout << endl;
    }
}