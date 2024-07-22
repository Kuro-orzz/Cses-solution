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
int a[maxn], st[4*maxn];

void build(int id, int l, int r){
    if(l == r){
        st[id] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = max(st[id*2], st[id*2+1]);
}

int get(int id, int l, int r, int val){
    if(l == r){
        if(st[id] >= val){
            st[id] -= val;
            return l;
        }
        else
            return 0;
    }
    int mid = (l+r)>>1;
    int ans = 0;
    if(st[id*2] >= val) ans = get(id*2, l, mid, val);
    else if(st[id*2+1] >= val) ans = get(id*2+1, mid+1, r, val);
    st[id] = max(st[id*2], st[id*2+1]);
    return ans;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        cout << get(1, 1, n, x) << " ";
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
