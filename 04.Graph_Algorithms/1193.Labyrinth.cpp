// #define _CRT_SECURE_NO_WARNINGS
// #include <bits/stdc++.h>
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <iomanip>
#include <climits>
using namespace std;

#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define N 1000000

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << '\n';
#else
#define debug(x...)
#endif

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

bool visited[1001][1001];
pii parent[1001][1001];
char way[1001][1001];
char adj[1001][1001];
char direct[] = {'U', 'L', 'R', 'D'};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n, m;
pii start; pii end;
string ans = "";

void bfs(pii a){
    queue<pii> q;
    q.push(a);
    visited[a.fi][a.se] = true;
    while(!q.empty()){
        pii v = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = v.fi + dx[i];
            int y = v.se + dy[i];
            if(x > 0 && x <= n && y > 0 && y <= m && !visited[x][y] && adj[x][y] != '#'){
                way[x][y] = direct[i];
                parent[x][y] = v;
                q.push({x, y});
                visited[x][y] = true;
            }
        }
    }
}

void path(pii s, pii t){
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    bfs(s);
    if(!visited[t.fi][t.se]){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        int cnt = 0;
        vector<char> path;
        while(t != s){
            path.pb(way[t.fi][t.se]);
            //path.push_back(t);
            t = parent[t.fi][t.se];
            cnt++;
        }
        //path.push_back(s);
        reverse(path.begin(), path.end());
        for(char i : path)
            ans += i;
        cout << cnt << '\n';
        cout << ans;
    }
}

void solve(){
    cin >> n >> m;
    pii start;
    pii end;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> adj[i][j];
            if(adj[i][j] == 'A')
                start = {i, j};
            if(adj[i][j] == 'B')
                end = {i, j};
        }
    path(start, end);
}

int main(){
    fast(); cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}
