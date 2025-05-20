#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9+7;

vector<vector<char>> a(1001, vector<char>(1001, 0));
vector<vector<ll>> dp(1001, vector<ll>(1001, 0));

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++){
        if(a[i][1] == '.')
            dp[i][1] = 1;
        else break;
    }
    for(int i = 1; i <= n; i++){
        if(a[1][i] == '.')
            dp[1][i] = 1;
        else break;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            if(a[i][j] == '.'){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            }
        }
    }
    cout << dp[n][n];
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    solve();
    return 0;
}
