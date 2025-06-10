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

ll sum_of_divisor(ll n) {
    ll res = 0, i = 1;
    while (i <= n) {
        ll l = i;          
        ll r = n / (n / i);
        ll val = n / l;
        ll csc = (u128)(r - l + 1) * (l + r) / 2 % MOD;
        res = (res + csc * val) % MOD;
        i = r + 1;
    }
    return res;
}

void solve() {
    ll n; cin >> n;
    cout << sum_of_divisor(n);
}

int main(){
    // std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}