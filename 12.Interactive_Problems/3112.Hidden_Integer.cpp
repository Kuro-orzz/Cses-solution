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

void solve() {
    int l = 0, r = 1e9;
    int cnt = 0;
    while (l < r && cnt < 30) {
        cnt++;
        int mid = (l + r) >> 1;
        cout << "? " << mid << '\n';
        cout.flush();
        string res; cin >> res;
        if (res == "YES") l = mid + 1;
        else r = mid;
    }
    cout << "! " << r << '\n';
    cout.flush();
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