/*
* Created By Mahmoud Qassem
* You are free to use any time...
* Problem Link:
* 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(s) (s).begin(),(s).end()
#define allr(s) (s).rbegin(),(s).rend()
#define T int t;cin>>t;while(t--)
#define OO INT_MAX
#define fx(x) fixed << setprecision(x)
#define mod 1000000007
void FastFile() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
//    freopen("input.txt", "r", stdin);
//    freopen("OOO.txt", "w", stdout);
}

void solve(){
    int n, m;
    cin >> n >> m;
    int segment = m / (n-1);

    if(segment&1){
        // down
        int crnt = m % (n - 1) + 1;
        cout << n - crnt + 1 << endl;
    }
    else {
        cout << m%(n-1) + 1 << endl;
    }
}

int32_t main() {
    FastFile();
    ll tc=1;
//    cin>>tc;
    for(ll i=1; i<=tc; ++i) {
        solve();
    }

}
