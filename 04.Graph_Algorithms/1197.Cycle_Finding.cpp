#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

struct Edge{
    int u, v, w;
};

vector<Edge> E;
vector<ll> d;

void bellman_ford(int n){
    d.resize(n+1, 1e18);
    vector<int> par(n+1);
    int st = -1;
    for(int i = 0; i < n; i++){
        st = -1;
        for(auto it : E){
            int u = it.u;
            int v = it.v;
            int w = it.w;
            if(d[v] > d[u]+w){
                d[v] = d[u]+w;
                par[v] = u;
                st = v;
            }
            if(u == v && w < 0){
                cout << "YES\n";
                cout << u << " " << v << '\n';
                return;
            }
        }
    }
    if(st == -1){
        cout << "NO";
        return;
    }
    int u = st;
    for(int i = 0; i < n; i++)
        u = par[u];
    vector<int> cycle = {u};
    for (int v = par[u]; v != u; v = par[v])
        cycle.push_back(v);
    cycle.push_back(u);
    reverse(cycle.begin(), cycle.end());
    cout << "YES\n";
    for(int x : cycle)
        cout << x << " ";
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        E.push_back({u, v, w});
    }
    bellman_ford(n);
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