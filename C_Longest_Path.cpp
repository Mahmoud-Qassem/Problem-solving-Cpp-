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
void FastFile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("OOO.txt", "w", stdout);
}
const int MAX = 100100;
int n, m;
vector<vector<int>> adj;
int dp[MAX];

int maxPath(int node)
{
    if (~dp[node])
        return dp[node];

    int mx = 0;
    for (auto ne : adj[node])
    {
        mx = max(mx, 1 + maxPath(ne));
    }
    return dp[node] = mx;
}

void solve()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n, vector<int>(0));
    for (int i = 0; i < m; ++i)
    {
        int from, to;
        cin >> from >> to;
        from--, to--;
        adj[from].push_back(to);
    }
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int node = 0; node < n;++node)
        ans = max(ans, maxPath(node));
    cout << ans << endl;
}

int32_t main()
{
    FastFile();
    ll tc = 1;
    //    cin>>tc;
    for (ll i = 1; i <= tc; ++i)
    {
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