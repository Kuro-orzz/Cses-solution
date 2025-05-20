#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <bitset>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <climits>
#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define N 100000
using namespace std;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    int a[n];
    int b[m];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    int cnt1 = 0;
    int cnt2 = 0;
    int res = 0;
    while(cnt1 < n && cnt2 < m){
        if(abs(a[cnt1]-b[cnt2]) <= k){
            cnt1++;
            cnt2++;
            res++;
        }
        else if(a[cnt1] < b[cnt2])
            cnt1++;
        else
            cnt2++;
    }
    cout << res;

}

int main(){
    fast();
    //filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}

