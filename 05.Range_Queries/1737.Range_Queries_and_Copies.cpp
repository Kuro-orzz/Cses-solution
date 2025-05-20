#pragma once

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define inf (ll)1e18

#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

const int mod = 998244353;

struct Node {
    Node *left, *right;
    ll sum;
    Node() {}
    Node(ll _sum): left(NULL), right(NULL), sum(_sum) {}
    Node(Node *l, Node *r, ll _sum): left(l), right(r), sum(_sum) {}
    ~Node() {
    	delete left;
    	delete right;
    }
};

class PersistentSegTree {
public:
	vector<Node*> ver;

	PersistentSegTree() {}
	PersistentSegTree(int n): ver(n+1) {}

	void build(Node *cur, int l, int r, const vector<int> &a) {
	    if (l == r) {
	        cur->sum = a[l];
	        return;
	    }
	    int mid = (l + r) >> 1;
	    cur->left = new Node(NULL, NULL, 0);
	    cur->right = new Node(NULL, NULL, 0);
	    build(cur->left, l, mid, a);
	    build(cur->right, mid+1, r, a);
	    cur->sum = cur->left->sum + cur->right->sum;
	}

	void update(Node *prev, Node *cur, int l, int r, int pos, ll x) {
	    if (l == r) {
	        cur->sum = x;
	        return;
	    }
	    int mid = (l + r) >> 1;
	    if (pos <= mid) {
	        cur->right = prev->right;
	        cur->left = new Node(NULL, NULL, 0);
	        update(prev->left, cur->left, l, mid, pos, x);
	    } else {
	        cur->left = prev->left;
	        cur->right = new Node(NULL, NULL, 0);
	        update(prev->right, cur->right, mid+1, r, pos, x);
	    }
	    cur->sum = cur->left->sum + cur->right->sum;
	}

	ll getSum(Node *cur, int l, int r, int u, int v) {
	    if (l > v || r < u) return 0;
	    if (u <= l && r <= v) return cur->sum;
	    int mid = (l + r) >> 1;
	    return getSum(cur->left, l, mid, u, v) + getSum(cur->right, mid+1, r, u, v);
	}
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    PersistentSegTree PST(n);
    Node *root = new Node(NULL, NULL, 0);
    PST.build(root, 1, n, a);
    
    int cntVer = 1;
    PST.ver[cntVer] = root;
    
    vector<int> arr = {0, 1};
    
    while (q--) {
        int tv; cin >> tv;
        if (tv == 1) {
            int k, pos, x; cin >> k >> pos >> x;

            PST.ver[++cntVer] = new Node(NULL, NULL, 0);
            Node *prev = PST.ver[arr[k]];
            Node *newRoot = PST.ver[cntVer];
            
            PST.update(prev, newRoot, 1, n, pos, x);
            arr[k] = cntVer;
        } else if (tv == 2) {
            int k, a, b; cin >> k >> a >> b;
            cout << PST.getSum(PST.ver[arr[k]], 1, n, a, b) << '\n';
        } else if (tv == 3) {
            int k; cin >> k;
            arr.push_back(arr[k]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}