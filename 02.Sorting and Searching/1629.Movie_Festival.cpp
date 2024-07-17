// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()
#define FOR(i, x, n) for(int i = x; i < n; i++)
#define REP(i, x, n) for(int i = x; i <= n; i++)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 10006

void solve(){
    int n; cin >> n;
    vector<pii> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].fi >> v[i].se;
    auto cmp = [&](pii a, pii b){
        if(a.se != b.se)
            return a.se < b.se;
        return a.fi < b.fi;
    };
    sort(all(v), cmp);
    int ans = 0;
    int t = 0;
    for(int i = 0; i < n; i++){
        if(v[i].fi >= t){
            ans++;
            t = v[i].se;
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
