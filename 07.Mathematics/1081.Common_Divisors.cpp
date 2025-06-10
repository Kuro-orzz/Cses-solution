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

const int N = 1e6 + 5;
int n, cnt[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    for (int i = N-1; i >= 0; i--) {
        int t = 0;
        for (int j = i; j < N; j += i) {
            t += cnt[j];
        }
        if (t >= 2) {
            cout << i << '\n';
            return;
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
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