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
vector<vector<int>> dp;

int bfs(int u, int n){
    queue<int> q;
    vector<int> vis(n+1, 0);
    vis[u] = 1;
    q.push(u);
    int res;
    while(!q.empty()){
        res = q.front(); q.pop();
        for(int x : adj[res]){
            if(!vis[x]){
                vis[x] = 1;
                q.push(x);
            }
        }
    }
    return res;
}

void dfs(int u, int par, int c, int dist){
    dp[u][c] = dist;
    for(int x : adj[u]){
        if(x != par)
            dfs(x, u, c, dist+1);
    }
}

void solve(){
    int n; cin >> n;
    adj.resize(n+1);
    dp.resize(n+1, vector<int>(2, 0));
    FOR(i, 0, n-1){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dist1 = bfs(1, n);
    int dist2 = bfs(dist1, n);
    dfs(dist1, -1, 0, 0);
    dfs(dist2, -1, 1, 0);
    for(int i = 1; i <= n; i++)
        cout << max(dp[i][0], dp[i][1]) << " ";
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
