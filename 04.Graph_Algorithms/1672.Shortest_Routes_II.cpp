#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vector<vector<ll>> d;

void floyd_warshall(int n){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = d[j][i] = min(d[i][j], d[i][k]+d[k][j]);
}

void solve(){
    int n, m, q; cin >> n >> m >> q;
    d.resize(n+1, vector<ll>(n+1, 1e18));
    for(int i = 0; i < m; i++){
        ll u, v, w; cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }
    floyd_warshall(n);
    while(q--){
        int a, b; cin >> a >> b;
        if(a == b)
            cout << 0 << '\n';
        else if(d[a][b] == 1e18)
            cout << -1 << '\n';
        else
            cout << d[a][b] << '\n'; 
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
