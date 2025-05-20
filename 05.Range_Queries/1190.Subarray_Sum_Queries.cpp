#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 2e5+1;

struct Node{
    ll ans, sum, suf, pre;
};

ll a[maxn];
Node st[4*maxn];

Node merge(Node a, Node b){
    Node c;
    c.ans = max({a.ans, b.ans, a.suf+b.pre});
    c.sum = a.sum+b.sum;
    c.pre = max(a.pre, a.sum+b.pre);
    c.suf = max(b.suf, a.suf+b.sum);
    return c;
}

void build(int id, int l, int r){
    if(l == r){
        st[id] = {max(a[l], 1ll*0), a[l], a[l], a[l]};
        return;
    }
    int mid = (l+r)>>1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = merge(st[id*2], st[id*2+1]);
}

void update(int id, int l, int r, int pos, int val){
    if(l > pos || r < pos) return;
    if(l == r){
        st[id] = {max(val, 0), val, val, val};
        return;
    }
    int mid = (l+r)>>1;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    st[id] = merge(st[id*2], st[id*2+1]);
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while(q--){
        int k, x; cin >> k >> x;
        update(1, 1, n, k, x);
        cout << st[1].ans << '\n';
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
