#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long h,w,X;
    cin >> h >> w >> X;
    unsigned long long p,q;
    cin >> p >> q;
    vector <vector<unsigned long long>> slim (h+2,vector<unsigned long long>(w+2, LONG_MAX));
    for (unsigned long long i = 1; i <= h; i++){
        for (unsigned long long j = 1; j <= w; j++)
            cin >> slim[i][j];
    }
    vector<vector<bool>> isVis(h+2,vector<bool>(w+2, false));
    unsigned long long now = slim[p][q];
    priority_queue<pair<unsigned long,pair<unsigned long,unsigned long>>, vector<pair<unsigned long,pair<unsigned long,unsigned long>>>, std::greater<pair<unsigned long,pair<unsigned long,unsigned long>>>> pq;
    pq.push({0,{p,q}});
    isVis[p][q] = true;
    while (!pq.empty()){
        unsigned long size = pq.top().first;
        unsigned long x = pq.top().second.first;
        unsigned long y = pq.top().second.second;
        pq.pop();
        if (size >= (now+X-1)/X){
            break;
        }
        now += size;
        if (!isVis[x][y+1]){
            isVis[x][y+1] = true;
            pq.push({slim[x][y+1],{x,y+1}});
        }
        if (!isVis[x+1][y]){
            isVis[x+1][y] = true;
            pq.push({slim[x+1][y],{x+1,y}});
        }
        if (!isVis[x][y-1]){
            isVis[x][y-1] = true;
            pq.push({slim[x][y-1],{x,y-1}});
        }
        if (!isVis[x-1][y]){
            isVis[x-1][y] = true;
            pq.push({slim[x-1][y],{x-1,y}});
        }
    }
    cout << now << endl;
}