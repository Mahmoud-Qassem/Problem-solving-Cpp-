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
const int MAX = 102;
int dp[MAX][MAX * 150];
int rec(int n, int one, int five, int ten)
{
    if (!n)
        return 0;

    if(~dp[n][one+five*5+ten*10])
        return dp[ten][one+five*5+ten*10];
    int mn = INT_MAX;
    if (ten)
    {
        mn = min(mn, 1 + rec(n - 1, one + 2, five, ten - 1));
    }
    if (five > 1)
    {
        mn = min(mn, 2 + rec(n - 1, one + 2, five - 2, ten));
    }
    if (five and one > 2)
        mn = min(mn, 4 + rec(n - 1, one - 3, five - 1, ten));
    if (one > 7)
        mn = min(mn, 8 + rec(n - 1, one - 8, five, ten));

    return dp[ten][one+five*5+ten*10]= mn;
}
void solve()
{
    int n, one, five, ten;
    cin >> n >> one >> five >> ten;
    memset(dp, -1, sizeof(dp));
    cout << rec(n, one, five, ten) << endl;
}

int32_t main()
{
    FastFile();
    ll tc = 1;
    cin >> tc;
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
