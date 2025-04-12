#include <bits/stdc++.h>
using namespace std;

long func(long n, vector <long>& dp){
    if (dp[n] != -1){
        return dp[n];
    }
    long temp = n;
    while (temp%2 == 0){
        temp = temp/2;
        if (dp[temp] != -1){
            return dp[temp];
        }
    }
    return dp[n] = temp;
}

int main(){
    int n;
    cin >> n;
    vector<long> arr(n);
    vector<long> brr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        brr[i] = arr[i];
    }
    sort(brr.begin(),brr.end());
    long t = brr[n-1]+brr[n-1];
    vector<long> dp(t+1,-1);
    long sum = 0;
    //cout << func(8,dp) << " " << func(12,dp) << " " << func(16,dp);
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            sum += func(arr[i]+arr[j],dp);
            //cout << sum << " ";
        }
    }
    cout << sum << endl;
    
}