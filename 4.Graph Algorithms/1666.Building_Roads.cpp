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
#define N 100000

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define fi first
#define se second

int n, m;
vi adj[N+6];
bool visited[N+6];
vi comp[N+6];
int cnt = 0;

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    comp[cnt].pb(u);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int x : adj[v])
            if(!visited[x]){
                comp[cnt].pb(x);
                q.push(x);
                visited[x] = true;
            }
    }
    cnt++;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            bfs(i);
    }
    cout << cnt-1 << '\n';
    for(int i = 1; i < cnt; i++)
        cout << comp[i-1][comp[i-1].size()-1] << " " << comp[i][0] << '\n';
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
