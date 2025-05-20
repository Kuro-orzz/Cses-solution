#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
 
vector<vector<char>> b(8, vector<char>(8));
vector<vector<int>> v(8, vector<int>(8, 0));
int ans = 0;
 
void set_vis(int x, int y, int vis){
    for(int i = 0; i < 8; i++){
        v[i][y] += vis;
        v[x][i] += vis;
    }
    for(int i = 0; i < 8; i++){
        if(x-i >= 0 && y-i >= 0)
            v[x-i][y-i] += vis;
        if(x-i >= 0 && y+i < 8)
            v[x-i][y+i] += vis;
        if(x+i < 8 && y-i >= 0)
            v[x+i][y-i] += vis;
        if(x+i < 8 && y+i < 8)
            v[x+i][y+i] += vis;
    }
}
 
void check(int x, int y){
    if(y == 7){
        ans++;
        return;
    }
    set_vis(x, y, 1);
    for(int i = 0; i < 8; i++){
        if(b[i][y+1] == '.' && !v[i][y+1])
            check(i, y+1);
    }
    set_vis(x, y, -1);
}
 
void solve(){
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin >> b[i][j];
    for(int i = 0; i < 8; i++)
        if(b[i][0] == '.')
            check(i, 0);
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
