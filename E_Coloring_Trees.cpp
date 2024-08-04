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
    //    freopen("input.txt", "r", stdin);
    //    freopen("OOO.txt", "w", stdout);
}
const ll MAX = 101;
ll n, m, k;
vector<ll> color;
vector<vector<ll>> cost;
ll dp[MAX][MAX][MAX];
ll rec(ll idx, ll myK, ll last) {
    // cout << idx + 1 << " " << myK << " " << last << endl;
    if (idx >= n) {
        if (myK == k)
            return 0;

        return 1e15;
    }
    if(~dp[idx][myK][last])
        return dp[idx][myK][last];

    ll mn = 1e16;
    if (color[idx] == 0) {
        for (ll C = 1; C <= m; ++C) {
            if (C == last)
                mn = min(mn, cost[idx][C - 1] + rec(idx + 1, myK, last));
            else
                mn = min(mn, cost[idx][C - 1] + rec(idx + 1, myK + 1, C));
        }
    }


    else {
        if (color[idx] != last)
            mn = min(mn, rec(idx + 1, myK + 1, color[idx]));
        else
            mn = min(mn, rec(idx + 1, myK, last));
    }
    // cout<<mn<<endl;
    return dp[idx][myK][last]=mn;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    color = vector<ll>(n + 2);
    for (ll i = 0; i < n; ++i) {
        cin >> color[i];
    }
    cost = vector<vector<ll>>(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j)
            cin >> cost[i][j];
    ll ans = LONG_LONG_MAX;
    if (!color[0]) {
        for (ll i = 1; i <= m; ++i) {
            ans = min(ans, cost[0][i - 1] + rec(1, 1, i));
        }
    } else {
        ans = min(ans, rec(1, 1, color[0]));
    }
    cout << (ans>=1e15?-1:ans )<< endl;

    // cou << rec(1) << endl;
}

int32_t main() {
    FastFile();
    ll tc = 1;
    //    cin>>tc;
    for (ll i = 1; i <= tc; ++i) {
        solve();
    }
}
/*
hints for dp
when you thinks that the problem can be solved with dp
you may ask yourself what should I dp for
the max of something
the min of something
the count of something
and then choose the parameters of the dp to DISTINGUISH the states of the dp
*/
