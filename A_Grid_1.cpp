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

const int MAX = 1010;
int n, m;
vector<string> grid;
bool valid(int x, int y)
{
    return x >= 0 and x < n and y >= 0 and y < m and grid[x][y]=='.';
}
int dp[MAX][MAX];
int rec(int i, int j)
{
    if (not valid(i,j))
        return 0;
    if(i==n-1 and j==m-1){
        return 1;
    }
    if(~dp[i][j]){
        return dp[i][j];
    }

    return dp[i][j] = (rec(i + 1, j) % mod + rec(i, j + 1) % mod) % mod;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    grid = vector<string>(n);
    for (auto &it : grid)
        cin >> it;
    cout << rec(0, 0) % mod << endl;
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