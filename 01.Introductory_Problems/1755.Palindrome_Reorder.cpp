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
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 100006
#define tuple64 tuple<ll, int, int>

void solve(){
    string s; cin >> s;
    map<char, int> mp;
    for(int i = 0; i < s.size(); i++)
        mp[s[i]]++;
    pair<char, int> odd{'0', 0};
    int check = 0;
    for(auto it : mp)
        if(it.se % 2 == 1){
            check++;
            odd = {it.fi, it.se};
        }
    if(check > 1){
        cout << "NO SOLUTION";
        return;
    }
    string ans = "";
    for(auto it : mp){
        if(it.se & 1) continue;
        for(int i = 0; i < it.se/2; i++)
            ans += it.fi;
        it.se /= 2;
    }
    string tmp = ans;
    reverse(all(tmp));
    cout << ans+string(odd.se, odd.fi)+tmp;
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

