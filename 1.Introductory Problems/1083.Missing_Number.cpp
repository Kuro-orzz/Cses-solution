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
    int n; cin >> n;
    int a[n+1];
    for(int i = 1; i < n; i++)
        cin >> a[i];
    sort(a+1, a+n);
    for(int i = 1; i < n; i++)
        if(a[i] != i){
            cout << i;
            return;
        }
    cout << n;
}

int main(){
    fast();
    //filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}

