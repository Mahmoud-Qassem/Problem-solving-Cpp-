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
const int MAX = 101;
int dp[MAX][5], n;
vector<int> v;

int rec(int idx = 0, int last = 0)
{
    if (idx >= n)
        return 0;
    if (~dp[idx][last])
        return dp[idx][last];


    int mx = 0;
    if (last == 0 )
    {
        if (v[idx] == 0)
            mx = rec(idx + 1, 0);

        else if (v[idx] == 1)
        {
            mx = max(1 + rec(idx + 1, 1), rec(idx + 1, 0));
        }
        else if (v[idx] == 2)
        {
            mx = max(1 + rec(idx + 1, 2), rec(idx + 1, 0));
        }
        else
        {
            mx = max({rec(idx + 1, 0),1 + rec(idx + 1, 2),1 + rec(idx + 1, 1)});
        }
    }
    if (last == 1)
    {
        if (v[idx] == 0)
            mx = rec(idx + 1, 0);
        else if (v[idx] == 1)
        {
            mx = rec(idx + 1, 0);
        }
        else
        {
            mx = max(1 + rec(idx + 1, 2), rec(idx + 1, 0));
        }
    }
    if (last == 2)
    {
        if (v[idx] == 0)
            mx = rec(idx + 1, 0);

        else if (v[idx] == 1)
        {
             mx = max(1 + rec(idx + 1, 1), rec(idx + 1, 0));
        }
        else if(v[idx]==2)
        {
            mx = rec(idx + 1, 0);
        }
        else{
            mx = max({1 + rec(idx + 1, 1), rec(idx + 1, 0)});
        }
    }

    return dp[idx][last] = mx;
}

void solve()
{
    cin >> n;

    memset(dp, -1, sizeof(dp));
    v = vector<int>(n);
    for (auto &ot : v)
        cin >> ot;
    cout << n - rec() << endl;
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
