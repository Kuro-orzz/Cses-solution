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
    int l, r, idx;
};
int a[maxn], block_sz;
vector<Node> queries;

bool cmp1(Node a, Node b){
    if(a.l/block_sz != b.l/block_sz)
        return a.l/block_sz < b.l/block_sz;
    return a.r < b.r;
}

bool cmp2(Node a, Node b){
    return a.idx < b.idx;
}

void query(){
    int cnt = 0;
    int cur_l = 1, cur_r = 0;
    sort(queries.begin(), queries.end(), cmp1);
    vector<int> fre(maxn, 0);
    auto del = [&](int l){
        if(fre[a[l]] == 1)
            cnt--;
        fre[a[l]]--;
    };
    auto add = [&](int r){
        if(fre[a[r]] == 0)
            cnt++;
        fre[a[r]]++;
    };
    vector<int> ans(queries.size());
    for(int i = 0; i < queries.size(); i++){
        int l = queries[i].l;
        int r = queries[i].r;
        while(cur_l > l){
            cur_l--;
            add(cur_l);
        }
        while(cur_r < r){
            cur_r++;
            add(cur_r);
        }
        while(cur_l < l){
            del(cur_l);
            cur_l++;
        }
        while(cur_r > r){
            del(cur_r);
            cur_r--;
        }
        ans[queries[i].idx] = cnt;
    }
    for(int x : ans)
        cout << x << '\n';
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    vector<pii> v;
    for(int i = 1; i <= n; i++)
        v.push_back({a[i], i});
    sort(all(v));
    int tmp = 0;
    for(int i = 0; i < n-1; i++){
        if(v[i].fi != v[i+1].fi){
            v[i].fi = tmp;
            tmp++;
        }
        else
            v[i].fi = tmp;
    }
    v[n-1].fi = tmp;
    sort(all(v), [&](pii a, pii b){return a.se < b.se;});
    for(int i = 1; i <= n; i++)
        a[i] = v[i-1].fi;
    block_sz = sqrt(n);
    queries.resize(q);
    for(int i = 0; i < q; i++){
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }
    query();
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
