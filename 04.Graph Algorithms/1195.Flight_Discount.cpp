// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
 
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 100006

vector<vector<pii>> adj, inv_adj;
vector<ll> d, inv_d;

void dijkstra(int n, int s, vector<ll> &d, vector<vector<pii>> &adj){
    vector<int> vis(n+1, 0);
    d.resize(n+1, 1e18);
    d[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().se;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto it : adj[u]){
            int v = it.fi;
            int w = it.se;
            if(d[v] > d[u]+w){
                d[v] = d[u]+w;
                pq.push({d[v], v});
            }
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    adj.resize(n+1);
    inv_adj.resize(n+1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        inv_adj[v].push_back({u, w});
    }
    dijkstra(n, 1, d, adj);
    dijkstra(n, n, inv_d, inv_adj);
    ll ans = 1e18;
    for(int u = 1; u <= n; u++)
        for(auto it : adj[u]){
            int v = it.fi;
            int w = it.se;
            ans = min(ans, d[u]+inv_d[v]+w/2);
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