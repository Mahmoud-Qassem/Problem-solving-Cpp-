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
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
}
const int MAX = 101;
int n, m;
vector<int> v;

int dp[MAX][MAX * MAX];
int rec(int idx, int rem)
{
    if (idx >= n)
        return 0;
    

    if (~dp[idx][rem])
        return dp[idx][rem];

    int mx = 0;
    if(rem>=v[idx]*(n-idx))
    mx = max(mx, 1 + rec(idx + 1, rem - v[idx]*(n-idx)));
    mx = max(mx, rec(idx + 1, rem));

    return dp[idx][rem] = mx;
}

void solve()
{
    cin >> n >> m;
    v = vector<int>(n);
    memset(dp, -1, sizeof(dp));
    for (auto &it : v)
        cin >> it;
    int ans = rec(0, m);
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