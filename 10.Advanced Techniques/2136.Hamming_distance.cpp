#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 2e4+6;
int n, k, a[maxn];

void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        a[i] = bitset<32>(s).to_ulong();
    }
    int ans = 31;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ans = min(ans, __builtin_popcount(a[i] ^ a[j]));
        }
    }
    cout << ans;
}
 
int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
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