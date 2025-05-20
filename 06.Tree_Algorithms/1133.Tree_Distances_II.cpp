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

vector<vector<int>> adj;
vector<ll> sz, d;

void dfs1(int u, int par, ll depth){
    d[1] += depth;
    sz[u] = 1;
    for(int v : adj[u]){
        if(v == par) continue;
        dfs1(v, u, depth+1);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int par){
    for(int v : adj[u]){
        if(v == par) continue;
        d[v] = d[u]+sz[1]-2*sz[v]; 
        dfs2(v, u);
    }
}

void solve(){
    int n; cin >> n;
    adj.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    sz.resize(n+1, 1);
    d.resize(n+1, 0);
    dfs1(1, 0, 0);
    dfs2(1, 0);
    for(int i = 1; i <= n; i++)
        cout << d[i] << " ";
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