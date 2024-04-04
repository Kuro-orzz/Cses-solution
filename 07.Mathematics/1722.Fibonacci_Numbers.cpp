
/*

------------------------------------Test in this problem is so weak-------------------------------
---------------------------should use log10(n)/log10(2) instead of log2(n)------------------------
---------------------------this problem in codeforce have better testcase-------------------------

*/
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
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define fi first
#define se second

void matrix(ll f[][2]){
    f[0][0] = 1;   f[0][1] = 1;
    f[1][0] = 1;   f[1][1] = 0;
}

void sqrMatrix(ll f[][2]){
    ll tmp[2][2];
    tmp[0][0] = (f[0][0] * f[0][0] % MOD + f[1][0] * f[0][1] % MOD) % MOD;
    tmp[0][1] = (f[0][1] * f[0][0] % MOD + f[1][1] * f[0][1] % MOD) % MOD;
    tmp[1][0] = tmp[0][1];
    tmp[1][1] = (f[0][1] * f[1][0] % MOD + f[1][1] * f[1][1] % MOD) % MOD;
    f[0][0] = tmp[0][0]; f[0][1] = tmp[0][1];
    f[1][0] = tmp[1][0]; f[1][1] = tmp[1][1];
}

void multiMatrix(ll a[][2], ll b[][1]){
    ll c[2][1];
    c[0][0] = (a[0][0] * b[0][0] % MOD + a[1][0] * b[1][0] % MOD) % MOD;
    c[1][0] = (a[0][1] * b[0][0] % MOD + a[1][1] * b[1][0] % MOD) % MOD;
    b[0][0] = c[0][0];
    b[1][0] = c[1][0];
}

ll binpow(int a, int b){
    if(b == 0)
        return 1;
    ll x = binpow(a, b/2);
    if(b % 2 == 0)
        return x * x;
    else
        return x * x * a;
}

void solve(){
    ll n; cin >> n;
    int a[100];
    int cnt = 0;
    if(n == 0){
        cout << 0;
        return;
    }
    n--;
    while(n > 0){
        a[cnt] = (int)(log10(n)/log10(2));
        n -= binpow(2, a[cnt]);
        cnt++;
    }
    ll ans[2][1] = {{1},
                    {0}};
    ll t[2][2];
    for(int i = 0; i < cnt; i++){
        matrix(t);
        for(int j = 0; j < a[i]; j++)
            sqrMatrix(t);
        multiMatrix(t, ans);
    }
    cout << ans[0][0] << endl;
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
