#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vector<vi> adj;
vi vis, path;
bool check = true;

void dfs(int u, int par){
    path.push_back(u);
    vis[u] = 1;
    for(int v : adj[u]){
        if(!check) return;
        if(v == par) continue;
        if(vis[v] && v != path[path.size()-2] && v != path[path.size()-1]){
            check = false;
            path.push_back(v);
            return;
        }
        else if(!vis[v])
            dfs(v, u); 
    }
    if(!check) return;
    path.pop_back();
}

void solve(){
    int n, m; cin >> n >> m;
    adj.resize(n+1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis.resize(n+1, 0);
    for(int i = 1; i <= n; i++)
        if(!vis[i]){
            path.clear();
            dfs(i, 0);
            if(!check) break;
        }
    if(check){
        cout << "IMPOSSIBLE";
        return;
    }
    vi ans = {path.back()};
    path.pop_back();
    while(path.back() != ans[0]){
        ans.push_back(path.back());
        path.pop_back();
    }
    ans.push_back(ans[0]);
    cout << ans.size() << '\n';
    for(int x : ans)
        cout << x << ' ';
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
