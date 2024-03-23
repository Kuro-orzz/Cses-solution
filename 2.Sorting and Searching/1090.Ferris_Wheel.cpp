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
    int n, x; cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    int cnt1 = 0;
    int cnt2 = n-1;
    int res = 0;
    while(cnt1 <= cnt2){
        if(a[cnt1] + a[cnt2] <= x){
            cnt1++;
            cnt2--;
            res++;
        }
        else{
            cnt2--;
            res++;
        }
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

