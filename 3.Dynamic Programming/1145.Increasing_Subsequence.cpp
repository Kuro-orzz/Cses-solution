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
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    multiset<int> ms;
    for(int x  : v){
        auto it = ms.lower_bound(x);
        if(it != ms.end())
            ms.erase(it);
        ms.insert(x);
    }
    cout << ms.size();
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
