#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int block_sz;
vector<ll> a, block;
vector<vector<ll>> lazy;

void preprocess(int n){
    block_sz = sqrt(n);
    block.resize(block_sz+2, 0);
    lazy.resize(block_sz+2, vector<ll>(2, 0));
    for(int i = 0; i < n; i++)
        block[i/block_sz] += a[i];
}

// update l->r
void upd1(int l, int r, ll val){
    int n = a.size();
    for(int i = l; i <= r;){
        if(i % block_sz == 0 && i+block_sz-1 <= r){
            lazy[i/block_sz][0] += val;
            i += block_sz;
        }
        else{
            int le = i/block_sz*block_sz;
            int ri = min(n-1, le+block_sz-1);
            block[i/block_sz] = 0;
            for(int j = le; j <= ri; j++){
                if(lazy[i/block_sz][1])
                    a[j] = lazy[i/block_sz][1]+lazy[i/block_sz][0];
                else
                    a[j] += lazy[i/block_sz][0];
                if(j >= l && j <= r)
                    a[j] += val;
                block[i/block_sz] += a[j];
            }
            lazy[i/block_sz][0] = lazy[i/block_sz][1] = 0;
            i = le+block_sz;
        }
    }
}
// set l->r
void upd2(int l, int r, ll val){
    int n = a.size();
    for(int i = l; i <= r;){
        if(i % block_sz == 0 && i+block_sz-1 <= r){
            lazy[i/block_sz][0] = 0;
            lazy[i/block_sz][1] = val;
            i += block_sz;
        }
        else{
            int le = i/block_sz*block_sz;
            int ri = min(n-1, le+block_sz-1);
            block[i/block_sz] = 0;
            for(int j = le; j <= ri; j++){
                if(lazy[i/block_sz][1])
                    a[j] = lazy[i/block_sz][1]+lazy[i/block_sz][0];
                else
                    a[j] += lazy[i/block_sz][0];
                if(j >= l && j <= r)
                    a[j] = val;
                block[i/block_sz] += a[j];
            }
            lazy[i/block_sz][0] = lazy[i/block_sz][1] = 0;
            i = le+block_sz;
        }
    }
}

ll get(int l, int r){
    ll ans = 0;
    int n = a.size();
    for(int i = l; i <= r;){
        if(i % block_sz == 0 && i+block_sz-1 <= r){
            if(lazy[i/block_sz][1])
                ans += lazy[i/block_sz][1]*block_sz+lazy[i/block_sz][0]*block_sz;
            else
                ans += block[i/block_sz]+lazy[i/block_sz][0]*block_sz;
            i += block_sz;
        }
        else{
            if(lazy[i/block_sz][1])
                ans += lazy[i/block_sz][1]+lazy[i/block_sz][0];
            else
                ans += a[i]+lazy[i/block_sz][0];
            i++;
        }
    }
    return ans;
}

void solve(){
    int n, q; cin >> n >> q;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    preprocess(n);
    while(q--){
        int tv, a, b; cin >> tv >> a >> b;
        a--, b--;
        if(tv == 1){
            ll x; cin >> x;
            upd1(a, b, x);
        }
        else if(tv == 2){
            ll x; cin >> x;
            upd2(a, b, x);
        }
        else
            cout << get(a, b) << '\n';
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
