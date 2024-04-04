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
#define N 10000000

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

void solve(){
    int n, target; cin >> n >> target;
    pii p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i].fi;
        p[i].se = i+1;
    }
    sort(p, p+n);
    int cnt1 = 0;
    int cnt2 = n-1;
    while(cnt1 != cnt2){
        if(p[cnt1].fi+p[cnt2].fi == target){
            cout << p[cnt1].se << " " << p[cnt2].se;
            return;
        }
        if(p[cnt1].fi+p[cnt2].fi > target)
            cnt2--;
        else
            cnt1++;
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
