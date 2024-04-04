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
#define N 1000000
using namespace std;

void solve(){
    int n; cin >> n;
    if(n == 1){
        cout << 1;
        return;
    }
    if(n < 4){
        cout << "NO SOLUTION";
        return;
    }
    for(int i = 0; i < n; i++)
        if(i % 2 == 0)
            cout << n/2+i/2+1 << " ";
        else
            cout << i/2+1 << " ";
}

int main(){
    fast();
    //filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}

