#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())
#define inf (ll)1e18

#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

const int N = 2e5 + 6;
int n, q;
vector<vector<int>> adj;
int st[N], en[N], tour[N];
int pos = 0;

template <typename T>
struct Fenwick{
    int n;
    vector<T> fen;

    Fenwick(int _n): n(_n), fen(_n+1) {}

    void update(int pos, int val) {
        for (; pos <= n; pos += pos & -pos) {
            fen[pos] += val;
        }
    }

    T get(int pos) {
        T ans = 0;
        for (; pos > 0; pos -= pos & -pos) {
            ans += fen[pos];
        }
        return ans;
    }

    T get(int l, int r) {
        return get(r) - get(l - 1);
    }

    void update_range(int l, int r, T val){
        update(l, val);
        update(r+1, -val);
    }

    void reset() {
        fill(all(fen), T(0));
    }
};

void dfs(int u ,int par = -1) {
    tour[++pos] = u;
    st[u] = pos;
    for (auto v : adj[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
    en[u] = pos;
}

void solve(){
    cin >> n >> q;
    int a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    adj.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    Fenwick<ll> BIT(n);
    for (int i = 1; i <= n; i++) {
        BIT.update(st[i], a[i]);
    }
    while (q--) {
        int type, u; cin >> type >> u;
        if (type == 1) {
            int v; cin >> v;
            ll oldVal = BIT.get(st[u], st[u]);
            BIT.update(st[u], v - oldVal);
        } else if (type == 2) {
            cout << BIT.get(st[u], en[u]) << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
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