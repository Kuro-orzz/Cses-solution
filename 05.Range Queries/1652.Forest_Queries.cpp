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
#define N 1000

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define fi first
#define se second

char a[N+1][N+1];
ll f[N+1][N+1];

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    f[0][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(a[i][j] == '*' && j == 1)
                f[i][j] = 1;
            else if(a[i][j] == '.' && j == 1)
                f[i][j] = 0;
            else if(a[i][j] == '*')
                f[i][j] = f[i][j-1] + 1;
            else if(a[i][j] == '.')
                f[i][j] = f[i][j-1];
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = 0;
        for(int i = a; i <= c; i++)
            ans += f[i][d] - f[i][b-1];
        cout << ans << '\n';
    }
}

int main(){
    fast(); //cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
