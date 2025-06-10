#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())
#define inf (ll)1e18

#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

using u128 = __uint128_t;

ll binMul(ll a, ll b, ll M) {
    a = a % M;
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % M;
        a = a * 2 % M;
        b /= 2;
    }
    return res;
}

ll binPow(ll a, ll b, ll M) {
    a %= M;
    ll res = 1;
    while (b) {
        if (b & 1) res = (u128)res * a % M;
        a = (u128)a * a % M;
        b /= 2;
    }
    return res;
}

bool test(ll a, ll n, ll k, ll m) {
    ll mod = binPow(a, m, n);
    if (mod == 1 || mod == n - 1) return true;
    for (int l = 1; l < k; l++) {
        mod = (u128)mod * mod % n;
        if (mod == n - 1) return true;
    }
    return false;
}

bool MillerRabin(ll n) {
    if (n <= 1) return false;
    ll k = 0, m = n-1;
    while (m % 2 == 0) {
        m /= 2;
        k++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (!test(a, n, k, m)) return false;
    }
    return true;
}

void solve() {
    ll n; cin >> n;
    while (true) {
        n++;
        if(MillerRabin(n)) {
            cout << n << '\n';
            return;
        }
    }
}

int main(){
    // std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}