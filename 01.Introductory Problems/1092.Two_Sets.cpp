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

void solve(){
    int n; cin >> n;
    if((1ll*n*(1+n)/2) % 2 != 0){
        cout << "NO";
        return;
    }
    unordered_set<int> s;
    ll tmp = 1ll*n*(1+n)/4;
    int p = n;
    while(p <= tmp){
        tmp -= p;
        s.insert(p);
        p--;
    }
    if(tmp)
        s.insert(tmp);
    cout << "YES" << '\n';
    cout << s.size() << '\n';
    for(int x : s)
        cout << x << " ";
    cout << '\n' << n-s.size() << '\n';
    for(int i = 1; i <= n; i++)
        if(s.find(i) == s.end())
            cout << i << " ";
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
