#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
// Miller–Rabin bases for n < 2^64
static const ll MR_WITNESSES[] = {
    2LL, 325LL, 9375LL, 28178LL, 450775LL, 9780504LL, 1795265022LL
};
static const int MR_CNT = sizeof(MR_WITNESSES)/sizeof(MR_WITNESSES[0]);

// Small primes for quick checks
static const int SMALL_P[] = {2,3,5,7,11,13,17,19,23,29,31,37};
static const int SMALL_CNT = sizeof(SMALL_P)/sizeof(SMALL_P[0]);

// O(log b) modular multiply
ll mod_mul(ll a, ll b, ll m) {
    ll res = 0;
    a %= m;
    while (b > 0) {
        if (b & 1) {
            res += a;
            if (res >= m) res -= m;
        }
        a <<= 1;
        if (a >= m) a -= m;
        b >>= 1;
    }
    return res;
}

ll mod_pow(ll base, ll exp, ll m) {
    ll res = 1 % m;
    while (exp > 0) {
        if (exp & 1) res = mod_mul(res, base, m);
        base = mod_mul(base, base, m);
        exp >>= 1;
    }
    return res;
}

bool isPrime(ll n) {
    if (n < 2) return false;
    for (int i = 0; i < SMALL_CNT; i++) {
        if (n == SMALL_P[i]) return true;
        if (n % SMALL_P[i] == 0) return false;
    }
    // Write n-1 = 2^s * m 
    ll d = n-1;
    ll s = 0;
    while((d&1) == 0){
        d >>= 1;
        s++;
    }
    for (int i = 0; i < MR_CNT; i++){
        ll a = MR_WITNESSES[i]%n;
        if (a==0)continue;
        ll num = mod_pow(a,d,n);
        if (num == 1 || num == n-1){
            continue;
        }
        bool comp = true;
        for (int r = 1; r < s; r++){
            num = mod_mul(num,num,n);
            if (num == n-1 || num == 1){
                comp = false;
                break;
            }
        }
        if (comp) return false;
    }
    return true;
}
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
void ak(){
    int x,y;
    cin >> x >> y;
    //int fx = 0;
    //int fy = 0;
    //int fxy = 0;
    vector<int> fx(14);
    vector<int> fy(7);
    fx[0] = 36;
    fx[1] = 36;
    fx[2] = 36;
    fx[3] = 35;
    fx[4] = 33;
    fx[5] = 30;
    fx[6] = 26;
    fx[7] = 21;
    fx[8] = 15;
    fx[9] = 10;
    fx[10] = 6;
    fx[11] = 3;
    fx[12] = 1;
    fx[13] = 0;

    fy[6] = 0;
    fy[5] = 2;
    fy[4] = 6;
    fy[3] = 12;
    fy[2] = 20;
    fy[1] = 30;
    fy[0] = 36;

    vector<vector<int>> fxy(14,vector<int>(7,0));
    fxy[2][0] ++;
    fxy[3][1] ++;
    fxy[4][2]++;
    fxy[5][3] ++;
    fxy[6][4]++;
    fxy[7][5]++;
    fxy[3][1]++;
    fxy[4][0]++;
    fxy[5][1]++;
    fxy[6][2]++;
    fxy[7][3]++;
    fxy[8][4]++;

    fxy[4][2]++;
    fxy[5][1]++;
    fxy[6][0]++;
    fxy[7][1]++;
    fxy[8][2]++;
    fxy[9][3]++;

    fxy[5][3]++;
    fxy[6][2]++;
    fxy[7][1]++;
    fxy[8][0]++;
    fxy[9][1]++;
    fxy[10][2]++;

    fxy[6][4]++;
    fxy[7][3]++;
    fxy[8][2]++;
    fxy[9][1]++;
    fxy[10][0] ++;
    fxy[11][1]++;

    fxy[7][5]++;
    fxy[8][4]++;
    fxy[9][3]++;
    fxy[10][2]++;
    fxy[11][1]++;
    fxy[12][0]++;

    int num = 0;
    for (int i = x; i <=13; i++){
        for (int j = y; j <= 6; j++){
            num += fxy[i][j];
        }
    }
    std::cout << std::fixed << std::setprecision(13) << 1.0*(fx[x]+fy[y]-num)/36 << "\n";
}
int32_t main(){
    int t = 1;
    //cin >> t;
    while(t--){
        ak();
    }
}