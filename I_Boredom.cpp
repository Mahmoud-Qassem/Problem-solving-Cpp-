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
const ll MAX = 100100;
ll dp[MAX];
ll freq[MAX *2];
ll rec(ll crnt){
    if(crnt==MAX)
        return 0;
    
    if(~dp[crnt])
        return dp[crnt];

    ll mx = 0;
    // take
    if(freq[crnt])
    mx = freq[crnt] *crnt + rec(crnt + 2);
    mx = max(mx, rec(crnt + 1));

    return dp[crnt] = mx;
}

void solve(){
    // if we remove one element
    // gain the cnt+frq[elem]
    memset(dp, -1, sizeof(dp));

    ll n;
    cin>>n;
    for (ll i = 0, x; i < n;++i){
        cin >> x;
        freq[x]++;
    }

    cout << rec(0) << endl;
}

int32_t main() {
    FastFile();
    ll tc=1;
//    cin>>tc;
    for(ll i=1; i<=tc; ++i) {
        solve();
    }

}
