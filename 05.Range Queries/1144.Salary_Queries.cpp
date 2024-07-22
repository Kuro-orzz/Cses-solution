#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

using ordered_set = tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set os;

void solve(){
    int n, q; cin >> n >> q;
    int a[n+1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        os.insert({a[i], i});
    }
    while(q--){
        char tv; cin >> tv;
        int u, v; cin >> u >> v;
        if(tv == '!'){
            os.erase({a[u], u});
            a[u] = v;
            os.insert({v, u});
        }
        else
            cout << os.order_of_key({v+1, 0})-os.order_of_key({u, 0}) << '\n';
    }
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
