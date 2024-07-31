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
    for(int i = 0; i < n; i++){
        cin >> v[i].fi;
        v[i].se = i;
    }
    sort(all(v), [&](pii a, pii b){return a.fi < b.fi;});
    int t = 1;
    for(int i = 0; i < n; i++){
        if(i+1 < n && v[i].fi != v[i+1].fi){
            v[i].fi = t;
            t++;
        }
        else
            v[i].fi = t;
    }
    sort(all(v), [&](pii a, pii b){return a.se < b.se;});
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        a[i] = v[i].fi;
    vector<int> cnt(2e5+6, 0);
    int l = 0, r = 0;
    int ans = 0;
    while(r < n){
        while(cnt[a[r]]){
            cnt[a[l]] = 0;
            l++;
        }
        cnt[a[r]] = 1;
        r++;
        ans = max(ans, r-l);
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
