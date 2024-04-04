// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD (int)(1e9+7)
#define INF ((1ll<<31)-1)
#define bit(mask, i) ((mask>>i)&1)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 100006
#define MASK64(x) (1LL << (x))

int n, m;
vi adj[maxn];
bool visited[maxn];
int ans[maxn];
bool check = true;


void dfs(int u, int team){
    visited[u] = true;
    ans[u] = team;
    for(int v : adj[u]){
        if(!visited[v]){
            if(team == 1)
                dfs(v, 2);
            else
                dfs(v, 1);
        }
        else{
            if(team == ans[v])
                check = false;
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    memset(visited, false, sizeof(visited));
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            dfs(i, 1);
    }
    if(!check){
        cout << "IMPOSSIBLE";
    }
    else{
        for(int i = 1; i <= n; i++)
            if(ans == 0)
                cout << 1 << " ";
            else
                cout << ans[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    cin.exceptions(cin.failbit);
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
