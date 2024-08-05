#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vector<int> bit;
int n, k;

int get(int x){
    int s = 0;
    while(x > 0){
        s += bit[x];
        x -= x&-x;
    }
    return s;
}
void update(int pos, int val){
    while(pos <= n){
        bit[pos] += val;
        pos += pos&-pos;
    }
}

void solve1(){
    cin >> n >> k;
    bit.resize(n+1);
    for(int i = 1; i <= n; i++)
        update(i, 1);
    int pos = 0;
    int cnt = 0;
    while(cnt < n){
        int t = k % get(n)+1;
        int l = pos, r = n;
        if(pos && get(r)-get(pos-1) < t){
            t -= get(r)-get(l-1);
            l = 1, r = n; pos = 0;
        }
        while(l < r){
            int mid = (l+r)>>1;
            if(get(mid)-get(pos) < t) l = mid+1;
            else if(get(mid)-get(pos) > t) r = mid-1;
            else r = mid;
        }
        pos = l;
        update(pos, -1);
        cout << pos << " ";
        cnt++;
    }
}

void solve2(){
    cin >> n >> k;
    ordered_set os;
    for(int i = 1; i <= n; i++)
        os.insert(i);
    int pos = 0;
    int cnt = 0;
    while(cnt < n){
        int t = k % (n-cnt);
        if(pos+t >= os.size()){
            t -= os.size()-pos;
            pos = 0;
        }
        pos+=t;
        cout << *os.find_by_order(pos) << ' ';
        os.erase(os.find_by_order(pos));
        cnt++;
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
        solve2();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
