#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

set<int> s[200005];
vector<int> color, ans;
vector<vector<int>> adj;

void dfs(int u, int par = 0){
    s[u].insert(color[u]);
    for(int v : adj[u]){
        if(v == par) continue;
        dfs(v, u);
        if(s[u].size() < s[v].size())
            swap(s[u], s[v]);
        for(int x : s[v])
            s[u].insert(x);
    }
    ans[u] = s[u].size();
}

void solve(){
    int n; cin >> n;
    color = ans = vector<int>(n+1);
    adj = vector<vector<int>>(n+1);
    for(int i = 1; i <= n; i++)
        cin >> color[i];
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
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
