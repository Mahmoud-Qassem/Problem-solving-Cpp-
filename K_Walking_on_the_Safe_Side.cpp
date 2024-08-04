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
map<pair<int, int>, bool> unsafe;
int n, m;
bool valid(int x, int y)
{
    return x >= 0 and x < n and y >= 0 and y < m;
}
const int MAX = 5000;
int dp[MAX][MAX];
int rec(int i = 0, int j = 0)
{
    if (i == n - 1 and j == m - 1)
        return 1;

    if (not valid(i, j))
        return 0;

    if (unsafe[{i, j}])
        return 0;

    if (~dp[i][j])
        return dp[i][j];

    return dp[i][j] = (rec(i + 1, j) + rec(i, j + 1));
}
void solve()
{
    unsafe.clear();
    memset(dp, -1, sizeof(dp));

    cin >> n >> m;

    for (int i = 0; i <= n; ++i)
    {
        int x, y;
        string s;
        getline(cin, s);
        // cout << s << endl;
        stringstream ss(s);
        string num;

        int cnt = 0;
        while (ss >> num)
        {
            cnt++;
            y = stoi(num);

            if (cnt == 1)
            {
                x = y;
                continue;
            }
            unsafe[{x - 1, y - 1}] = 1;
            // cout << x << " " << y << endl;
            // unsafe[{y, x}] = 1;
        }
    }

    cout << rec() << endl;
}

int32_t main()
{
    FastFile();
    ll tc = 1;
    cin >> tc;
    for (ll i = 1; i <= tc; ++i)
    {
        solve();
        if(i<tc)
        cout << endl;
    }
}
