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
    ll n,m;
    cin >> n >> m;
    vector<ll> pre(n+1,0);
    for (ll i = 0; i < m; i++){
        ll l,r;
        cin >> l >> r;
        pre[l]++;
        if (r != n){
            pre[r+1]--;
        }
    }
    vector<ll> sum(n+1,0);
    sum[1] = pre[1];
    for (ll i = 2; i <= n; i++){
        sum[i] = sum[i-1]+pre[i];
    }
    ll ans = LLONG_MAX;
    for (ll i = 1; i <= n; i++){
        ans = min(ans,sum[i]);
    }
    cout << ans << "\n";
}
int32_t main(){
    int t = 1;
    //cin >> t;
    while(t--){
        ak();
    }
}
