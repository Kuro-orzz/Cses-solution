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
#define MOD (int)(1e9+7)
#define N 100000

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

int n, k, isfinal = 0;
int a[100];
string s;

void ktao(){
    // for(int i = 0; i <= n; i++)
    //     a[i] = i;
    sort(s.begin(), s.end());
}

void sinh(){
    int i = s.length()-2;
    while(i >= 0 && s[i] >= s[i+1]){
        i--;
    }
    if(i == -1)
        isfinal = 1;
    else{
        int j = s.length()-1;
        while(s[j] <= s[i])
            j--;
        swap(s[i], s[j]);
        reverse(s.begin()+i+1, s.end());
    }
}

string ans[N];
void solve(){
    cin >> s;
    ktao();
    int cnt = 0;
    while(!isfinal){
        // for(int i = 1; i <= n; i++)
        //     cout << a[i];
        ans[cnt] = s;
        cnt++;
        sinh();
    }
    cout << cnt << '\n';
    for(int i = 0; i < cnt; i++)
        cout << ans[i] << '\n';
}

int main(){
    fast();
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}

