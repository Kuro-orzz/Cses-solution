#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

struct Lca{
    vector<vector<int>> adj;
    vector<int> h;
    vector<vector<int>> up;
    Lca(int n): adj(n+1), h(n+1, 0), up(n+1, vector<int>(20)){}

    int ancestor_k(int u, int k){
        for(int j = 0; (1 << j) <= k; j++){
            if(k >> j & 1)
                u = up[u][j];
        }
        return u;
    }

    void dfs(int u, int p){
        for(int v : adj[u]){
            if(v == p) continue;
            up[v][0] = u;
            h[v] = h[u] + 1;
            for(int j = 1; j < 20; j++)
                up[v][j] = up[up[v][j-1]][j-1];
            dfs(v, u);
        }
    }

    int _lca(int u, int v){
        if(h[u] < h[v]) swap(u, v);
        int k = h[u]-h[v];
        u = ancestor_k(u, k);
        if(u == v) return u;

        k = __lg(h[u]);
        for(int j = k; j >= 0; j--){
            if(up[u][j] != up[v][j]){
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
};

void solve(){
    int n, q; cin >> n >> q;
    Lca lca(n);
    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        lca.adj[i].push_back(x);
        lca.adj[x].push_back(i);
    }
    lca.dfs(1, 0);
    while(q--){
        int u, v; cin >> u >> v;
        cout << lca._lca(u, v) << '\n';
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
