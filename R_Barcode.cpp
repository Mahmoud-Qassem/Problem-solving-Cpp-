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
const ll MAX = 1001;
ll n, m, x, y;
vector<ll> white(MAX), black(MAX);

ll dp[MAX][MAX][4];
ll rec(ll idx, ll monochrome = 0, ll color = 2)
{
    // cout << idx << " " << monochrome << endl;

    if (idx >= m)
    {
        if (monochrome >= x and monochrome <= y)
            return 0;
        else
            return 1e12;
    }

    if (~dp[idx][monochrome][color])
        return dp[idx][monochrome][color];

    ll mn = 1e15;

    if (monochrome < x)
    {
        // should be the same color
        if (color == 0)
        {
            mn = min(mn, n - black[idx] + rec(idx + 1, monochrome + 1, color));
        }
        else if (color == 1)
        {
            mn = min(mn, n - white[idx] + rec(idx + 1, monochrome + 1, color));
        }
        else
        {
            mn = min(mn, n - white[idx] + rec(idx + 1, monochrome + 1, 1));
            mn = min(mn, n - black[idx] + rec(idx + 1, monochrome + 1, 0));
        }
    }
    else if (monochrome < y)
    {
        // free to choose
        if (color == 0)
        {
            mn = min(mn, n - black[idx] + rec(idx + 1, monochrome + 1, color));
            mn = min(mn, n - white[idx] + rec(idx + 1, 1, 1));
        }
        else if (color == 1)
        {
            mn = min(mn, n - white[idx] + rec(idx + 1, monochrome + 1, color));
            mn = min(mn, n - black[idx] + rec(idx + 1, 1, 0));
        }

    } // == y
    else
    {
        // should be the opposite color
        if (color == 0)
        {
            mn = min(mn, n - white[idx] + rec(idx + 1, 1, 1));
        }
        else if (color == 1)
        {
            mn = min(mn, n - black[idx] + rec(idx + 1, 1, 0));
        }
    }
    return dp[idx][monochrome][color] = mn;
}

void solve()
{
    cin >> n >> m >> x >> y;
    memset(dp, -1, sizeof(dp));
    for (ll i = 0; i < n; ++i)
    {
        string s;
        cin >> s;

        for (ll j = 0; j < m; ++j)
        {
            white[j]+= s[j] == '.';
            black[j]+= s[j] == '#';
        }
    }
    


    ll ans = rec(0);
    cout << ans << endl;
    // # of conseq. balck or white cols should be >=x and <=y
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
