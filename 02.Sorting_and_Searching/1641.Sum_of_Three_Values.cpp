// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD (int)(1e9+7)
#define N 1000000

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

void solve(){
    int n, x; cin >> n >> x;
    pii p[n];
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> p[i].fi;
        p[i].se = i;
        a[i] = p[i].fi;
    }
    if(n < 3){
        cout << "IMPOSSIBLE";
        return;
    }
    sort(p, p+n);
    sort(a, a+n);
    for(int i = 0; i < n; i++){
        int cnt1 = i;
        int cnt2 = i+1;
        while(cnt2 < n && a[cnt1] + a[cnt2] < x){
            int target = x-a[cnt1]-a[cnt2];
            if(binary_search(a+cnt2+1, a+n, target)){
                auto k = lower_bound(a+cnt2+1, a+n, target);
                cout << p[cnt1].se+1 << " " << p[cnt2].se+1 << " " << p[k-a].se+1;
                return;
            }
            cnt2++;
        }
    }
    cout << "IMPOSSIBLE";
}

int main(){
    fast();
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
