#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9+7;

vector<int> price(1001);
vector<int> pages(1001);
vector<vector<int>> dp(1001, vector<int>(100001, 0));

void solve(){
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> price[i];
    for(int i = 1; i <= n; i++)
        cin >> pages[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j] = dp[i-1][j];
            if(price[i] <= j)
                dp[i][j] = max(dp[i][j], dp[i-1][j-price[i]]+pages[i]);
        }
    }
    cout << dp[n][k];
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    solve();
    return 0;
}
