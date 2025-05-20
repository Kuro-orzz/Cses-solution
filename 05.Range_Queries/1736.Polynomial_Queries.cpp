#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 2e5+6;
ll a[maxn], st[4*maxn];
pair<ll, ll> lazy[4*maxn];

ll sum(int l, int r){
    return 1ll*(r-l+1)*(l+r)/2;
}

void build(int id, int l, int r){
    if(l == r){
        st[id] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = st[id*2]+st[id*2+1];
}

void push(int id, int l, int r){
    int mid = (l+r)>>1;
    if(lazy[id].fi){
        st[id*2] += sum(1, mid-l+1)*lazy[id].fi;
        lazy[id*2].fi += lazy[id].fi;
        st[id*2+1] += 1ll*(r-mid)*(mid-l+1)*lazy[id].fi+sum(1, r-mid)*lazy[id].fi;
        lazy[id*2+1].fi += lazy[id].fi;
        lazy[id*2+1].se += (mid-l+1)*lazy[id].fi;
        lazy[id].fi = 0;
    }
    if(lazy[id].se){
        st[id*2] += lazy[id].se*(mid-l+1);
        st[id*2+1] += lazy[id].se*(r-mid);
        lazy[id*2].se += lazy[id].se;
        lazy[id*2+1].se += lazy[id].se;
        lazy[id].se = 0;
    }
}

ll get(int id, int l, int r, int u, int v){
    if(u > r || v < l) return 0;
    if(u <= l && v >= r) return st[id];
    push(id, l, r);
    int mid = (l+r)>>1;
    return get(id*2, l, mid, u, v)+get(id*2+1, mid+1, r, u, v);
}

void update(int id, int l, int r, int u, int v){
    if(u > r || v < l) return;
    if(u <= l && v >= r){
        st[id] += 1ll*(l-u)*(r-l+1)+sum(1, r-l+1);
        lazy[id].fi++;
        lazy[id].se += l-u;
        return;
    }
    push(id, l, r);
    int mid = (l+r)>>1;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    st[id] = st[id*2]+st[id*2+1];
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while(q--){
        int tv, l, r; cin >> tv >> l >> r;
        if(tv == 1)
            update(1, 1, n, l, r);
        else
            cout << get(1, 1, n, l, r) << '\n';
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
