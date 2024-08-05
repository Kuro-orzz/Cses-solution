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
    int x, n; cin >> x >> n;
    vi p(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];
    set<pii> s;
    unordered_map<int, int> r;
    s.insert({0, x});
    priority_queue<int> pq;
    pq.push(x);
    for(int i = 0; i < n; i++){
        auto it = s.lower_bound({p[i], 0});
        it = prev(it);
        pii t = {(*it).fi, (*it).se};
        s.erase(it);
        r[t.se-t.fi]++;
        s.insert({t.fi, p[i]});
        s.insert({p[i], t.se});
        pq.push(p[i]-t.fi);
        pq.push(t.se-p[i]);
        while(r[pq.top()]){
            r[pq.top()]--;
            pq.pop();
        }
        cout << pq.top() << ' ';
    }
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
