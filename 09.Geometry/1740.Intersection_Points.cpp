#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

struct Fenwick{
    vector<ll> fen;
    Fenwick(int n): fen(n+2, 0){};
    ll get(int pos){
        ll ans = 0;
        while(pos){
            ans += fen[pos];
            pos -= (pos & -pos);
        }
        return ans;
    }
    void update(int pos, int val){
        while(pos < fen.size()){
            fen[pos] += val;
            pos += (pos & -pos);
        }
    }
    void update_range(int l, int r, int val){
        update(l, val);
        update(r+1, -val);
    }
};

struct Point {
    int x, type, y1, y2;
    Point() {}
    Point(int x, int type, int y1, int y2){
        this->x = x;
        this->type = type;
        this->y1 = y1;
        this->y2 = y2;
    }

    bool operator < (Point other){
        if(this->x != other.x)
            return this->x < other.x;
        return this->type < other.type;
    }
};

void solve(){
    const int N = 1e6;
    int n; cin >> n;
    Fenwick fw(2*N+6);
    vector<Point> v;
    for(int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a += N;
        b += N;
        c += N;
        d += N;
        if(b == d){ // Horizontal
            if(a > c) swap(a, c);
            v.push_back(Point(a, 0, b, 0));
            v.push_back(Point(c, 2, d, 0));
        }
        else if(a == c){ // Vertical
            if(b > d) swap(b, d);
            v.push_back(Point(a, 1, b, d));
        }
    }
    sort(all(v));
    ll ans = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].type == 0)
            fw.update(v[i].y1, 1);
        else if(v[i].type == 2)
            fw.update(v[i].y1, -1);
        else if(v[i].type == 1)
            ans += fw.get(v[i].y2)-fw.get(v[i].y1-1);
    }
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
