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

struct Edge{
    int u, v, w;
};

vector<Edge> E;
vector<ll> d;

void bellman_ford(int n){
    d[1] = 0;
    for(int i = 1; i < n; i++){
        for(auto Edge : E){
            int u = Edge.u;
            int v = Edge.v;
            int w = Edge.w;
            if(d[u] != 1e18)
                d[v] = min(d[v], d[u]+w);
        }
    }
    for(int i = 0; i < n; i++){
        for(auto Edge : E){
            int u = Edge.u;
            int v = Edge.v;
            int w = Edge.w;
            if(d[u] != 1e18 && d[v] > d[u]+w)
                d[v] = -1e18;
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        E.push_back({u, v, -w});
    }
    d.resize(n+1, 1e18);
    bellman_ford(n);
    cout << (-d[n] != 1e18 ? -d[n] : -1);
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