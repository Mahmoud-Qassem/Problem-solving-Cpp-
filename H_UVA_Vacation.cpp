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

string a, b;
int dp[MAX][MAX];
int n, m;

int rec(int i, int j)
{
    if (i >= n or j >= m)
        return 0;

    if (~dp[i][j])
        return dp[i][j];
    int mx = 0;
    if (a[i] != b[j])
    {
        mx = max(rec(i, 1 + j), rec(1 + i, j));
    }
    else
        mx = max({rec(i, 1 + j), 1 + rec(i + 1, 1 + j), rec(1 + i, j)});

    // cout << i+1 << " " << j+1 << " " << mx << endl;
    return dp[i][j] = mx;
}
int solve()
{

    return rec(0, 0);
}

int32_t main()
{
    FastFile();
    ll tc = 1;
    //    cin>>tc;
    for (ll i = 1;; ++i)
    {
        a.clear(), b.clear();
        // cin >> a;
        getline(cin, a);

        if (a == string("#"))
            break;
        getline(cin, b);
        // cin >> b;
        // cout << a << " " << b << endl;

        memset(dp, -1, sizeof(dp));
        n = a.size();
        m = b.size();
        cout << "Case #" << i << ": you can visit at most " << rec(0, 0) << " cities." << endl;
    }
}
