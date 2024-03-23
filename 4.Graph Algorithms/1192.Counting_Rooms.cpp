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
#define MOD 1000000007
#define N 1000000

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define fi first
#define se second

bool visited[1001][1001];
char adj[1001][1001];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n, m;

void bfs(int a, int b){
    queue<pii> q;
    q.push({a, b});
    visited[a][b] = true;
    while(!q.empty()){
        pii v = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = v.fi + dx[i];
            int y = v.se + dy[i];
            if(x > 0 && x <= n && y > 0 && y <= m && !visited[x][y] && adj[x][y]=='.'){
                q.push({x, y});
                visited[x][y] = true;
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> adj[i][j];
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(adj[i][j] == '.' && !visited[i][j]){
                bfs(i, j);
                cnt++;
            }
    cout << cnt;
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
