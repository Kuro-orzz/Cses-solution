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
vector<int> par, lca, d;
vector<vector<int>> up;

void preprocess(int n){
    up.resize(n+1, vector<int>(20));
    for(int i = 1; i <= n; i++)
        up[i][0] = par[i];
    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= n; j++)
            up[j][i] = up[up[j][i-1]][i-1];
    } 
}

int ancestor_k(int u, int x){
    for(int i = 19; i >= 0; i--)
        if(x >= (1 << i)){
            u = up[u][i];
            x -= (1 << i);
        }
    return u;
}

void dfs(int u, int par, int depth){
    d[u] = depth;
    for(int v : adj[u]){
        if(v == par) continue;
        dfs(v, u, depth+1);
    }
}

void solve(){
    int n, q; cin >> n >> q;
    adj.resize(n+1);
    par.resize(n+1);
    d.resize(n+1);
    par[1] = 1;
    for(int i = 2; i <= n; i++){
        cin >> par[i];
        adj[i].pb(par[i]);
        adj[par[i]].pb(i);
    }
    dfs(1, 0, 0);
    preprocess(n);
    while(q--){
        int u, x; cin >> u >> x;
        if(d[u] < x)
            cout << -1 << '\n';
        else
            cout << ancestor_k(u, x) << '\n';
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