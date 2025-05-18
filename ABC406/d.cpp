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
   int h,w,n;
   unordered_map<int,unordered_set<int>> xv; // Do not store y coords
   unordered_map<int,unordered_set<int>> yv;
   cin >>h >> w >> n;
   vector<int> is_removed(n); // Store the indices of the trash
   vector<bool> ax(h+1,false),ay(w+1,false); // Row or column has been previously queried
   for (int i = 0; i < n; i++){
    int xi,yi;
    cin >> xi >> yi;
    xv[xi].insert(i);
    yv[yi].insert(i);
   }
   int q;
   cin >> q;
   for (int i = 0; i < q; i++){
    int num,a;
    cin >> a >> num;
    if (a == 1){
        if (ax[num] == true){
            cout << 0 << "\n";
        }
        else {
            int ans = 0;
            for (int e : xv[num]){
                if (!is_removed[e]){
                    is_removed[e] = true;
                    ans ++;
                }
            }
            ax[num] = true; // Do not forget to mark this row as visited so that u do not end up visiting it again
            cout << ans << "\n";
        }
    }
    else {
        if (ay[num] == true){
            cout << 0 << "\n";
        }
        else {
            int ans = 0;
            for (int e : yv[num]){
                if (!is_removed[e]){
                    is_removed[e] = true;
                    ans ++;
                }
            }
            cout << ans << "\n";
            ay[num] = true;
        }
   }
}
}
int32_t main(){
    int t = 1;
    //cin >> t;
    while(t--){
        ak();
    }
}
