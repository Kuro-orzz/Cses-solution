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

const int maxn = 41;
ll n, k;
vector<ll> a, L, R;
 
void MITM(int i, ll sum, int end) {
    if (sum > k) return;
    if (i >= end) R.push_back(sum);
    else {
        MITM(i+1, sum, end);
        MITM(i+1, sum+a[i], end);
    } 
}
 
void solve() {
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    MITM(0, 0, n/2);
    L = R;
    R.clear();
    MITM(n/2, 0, n);
    sort(all(L));
    sort(all(R));
    ll ans = 0;
    for (ll x : L) {
        ans += upper_bound(all(R), k-x) - lower_bound(all(R), k-x);
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
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