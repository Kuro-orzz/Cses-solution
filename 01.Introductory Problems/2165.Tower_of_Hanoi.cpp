#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vector<pii> ans;

void solve(int n, int l, int m, int r){
    if(n == 0) return;
    solve(n-1, l, r, m);
    ans.push_back({l, r});
    solve(n-1, m, l, r);
}

void solve(){
    int n; cin >> n;
    solve(n, 1, 2, 3);
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].fi << " " << ans[i].se << '\n';
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
