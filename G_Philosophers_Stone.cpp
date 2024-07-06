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
const int MAX = 1e2 + 2;
int dp[MAX][MAX];
int n, m;
vector<vector<int>> grid;

// Flatten=i*m+j+1
// x=Flatten/m
// y=Flatten%m
bool valid(int x, int y)
{
    return x >= 0 and x < n and y >= 0 and y < m;
}

int rec(int i, int j)
{
    if (!valid(i, j))
        return 0;

    if (~dp[i][j])
        return dp[i][j];

    int mx = grid[i][j] + rec(i + 1, j);
    mx = max(mx, grid[i][j] + rec(i + 1, j - 1));
    mx = max(mx, grid[i][j] + rec(i + 1, j + 1));

    return dp[i][j] = mx;
}
void solve()
{
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));

    grid = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }
    int mx = 0;
    for (int i = 0; i < m; ++i)
    {
        mx = max(mx, rec(0, i));
        // rec(0, v[0])
    }
    cout << mx << endl;
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
