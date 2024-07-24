#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    int n, m; cin >> n >> m;
    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<ll>> dp(n, vector<ll>(106, 0));
    if(!a[0]){
        for(int i = 1; i <= m; i++)
            dp[0][i] = 1;
    }
    else
        dp[0][a[0]] = 1;
    for(int i = 1; i < n; i++){
        if(a[i] == 0){
            for(int j = 1; j <= m; j++)
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%MOD;
        }
        else{
            dp[i][a[i]] = (dp[i-1][a[i]]+dp[i-1][a[i]-1]+dp[i-1][a[i]+1])%MOD;
        }
    }
    ll ans = 0;
    for(int i = 1; i <= m; i++)
        ans = (ans+dp[n-1][i]) % MOD;   
    cout << ans;
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
