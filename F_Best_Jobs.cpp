/*
 * Created By Mahmoud Qassem
 * You are free to use any time...
 * Problem Link:
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(s) (s).begin(), (s).end()
#define allr(s) (s).rbegin(), (s).rend()
#define T     \
    int t;    \
    cin >> t; \
    while (t--)
#define OO INT_MAX
#define fx(x) fixed << setprecision(x)
#define mod 1000000007
void FastFile() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
//    freopen("jobs.in", "r", stdin);
    //    freopen("OOO.txt", "w", stdout);
}
const int MAX = 1010;
ll n;
vector< pair< pair<int,int>,int > > sorted;
vector<ll> gain;
ll cost[MAX][MAX];
ll dp[MAX][MAX];

ll rec(int j, int i) {
    int actual_i = sorted[i].second;
    int actual_j = sorted[j].second;

    if (j >= n + 1)
        return gain[actual_i];
 
    if (~dp[j][i])
        return dp[j][i];
 
    // leave it

    ll mx = rec(j + 1, i);
    // take it
    if (cost[actual_i][actual_j] !=-1 )
        mx = max(mx, gain[actual_i]  - cost[actual_i][actual_j] + rec(j + 1, j));
 
 
    return dp[j][i] = mx;
}

void solve() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    memset(cost, 0, sizeof(dp));
    sorted = vector < pair< pair<int,int>,int > >(n +1);
    gain = vector< ll >(n + 5,0);

    for (ll i = 1; i <= n; ++i)
        cin >> sorted[i].first.second;
    for (ll i = 1; i <= n; ++i)
        cin >> sorted[i].first.first,sorted[i].second=i;

    for (ll i = 1; i <= n; ++i)
        cin >> gain[i];

    sort(sorted.begin()+1,sorted.begin()+n+1);

    // for(auto&it:sorted){
    //     cout << it.first.first << " " << it.first.second << " " << it.second << endl;
    // }
    
    for (ll i = 1; i <= n; ++i)
        for (ll j = 1; j <= n; ++j)
            cin >> cost[i][j];

            
    cout << rec(0, 0) << endl;
}

int32_t main() {
    FastFile();
    ll tc = 1;
    cin >> tc;
    for (ll i = 1; i <= tc; ++i) {
        solve();
    }
}
