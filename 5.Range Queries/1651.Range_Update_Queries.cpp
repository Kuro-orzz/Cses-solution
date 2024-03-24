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
#define maxn 200006
#define tuple64 tuple<ll, int, int>

ll a[maxn], st[4*maxn], lazy[4*maxn];

void push(int id){
    if(lazy[id]){
        st[id*2] += lazy[id];
        st[id*2+1] += lazy[id];
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
        lazy[id] = 0;
    }
}

ll get(int id, int l, int r, int u, int v){
    if(r < u | v < l)
        return 0;
    if(u <= l && v >= r)
        return st[id];
    int mid = (l+r)/2;
    push(id);
    ll t1 = get(id*2, l, mid, u, v);
    ll t2 = get(id*2+1, mid+1, r, u, v);
    return t1 + t2;
}

void update(int id, int l, int r, int u, int v, int val){
    if(v < l || u > r)
        return;
    if(u <= l && v >= r){
        a[l] += val;
        st[id] += val;
        lazy[id] += val;
        return;
    }
    int mid = (l+r)/2;
    push(id);
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    st[id] = st[id*2] + st[id*2+1];
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        update(1, 1, n, i, i, a[i]);
    }
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int a, b, u; cin >> a >> b >> u;
            update(1, 1, n, a, b, u);
        }
        else{
            int k; cin >> k;
            cout << get(1, 1, n, k, k) << '\n';
        }
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

