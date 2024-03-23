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
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define fi first
#define se second

ll powMod(ll a, ll b, ll m){
    ll res = 1;
    a %= m;
    while(b){
        if(b % 2 == 1){
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        b /= 2;
    }
    return res;
}

ll inverse(ll a, ll m){
    return powMod(a, m-2, m);
}

ll gt[N+6];
void solve(){
    string s; cin >> s;
    unordered_map<char, int> mp;
    int n = s.length();
    for(int i = 0; i < s.length(); i++)
        mp[s[i]]++;
    gt[0] = gt[1] = 1;
    for(int i = 2; i <= N; i++)
        gt[i] = (gt[i-1] * i) % MOD;
    ll ans = 1;
    for(auto it : mp){
        ans *= (gt[n]*inverse(gt[n-it.se]*gt[it.se]%MOD, MOD))%MOD;
        ans %= MOD;
        n -= it.se;
    }
    cout << ans;
}
// --------SOLUTION 2---------------
//    string s; cin >> s;
//    gt[0] = gt[1] = 1;
//    for(int i = 2; i <= N; i++){
//        gt[i] = (gt[i-1] * i)%MOD;
//    }
//    unordered_map<char, int> mp;
//    for(int i = 0; i < s.length(); i++)
//        mp[s[i]]++;
//    ll tmp = 1;
//    for(auto it : mp){
//        tmp *= gt[it.se];
//        tmp %= MOD;
//    }
//    cout << (gt[s.length()] * inverse(tmp, MOD)) % MOD;

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
