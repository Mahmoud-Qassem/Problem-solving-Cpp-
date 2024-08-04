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
string s;
int n;
const int MAX = 1001;
int dp[MAX][MAX];
int rec(int i, int j)
{
    if(i>=j)
        return 0;
    
    if(~dp[i][j])
        return dp[i][j];

    int mn = INT_MAX;
    if (s[i] != s[j])
    {
        // replace
        mn = min(mn, 1 + rec(i + 1, j - 1));
        // remove
        mn = min({mn, 2 + rec(i + 1, j - 1), 1 + rec(i + 1, j), 1 + rec(i, j - 1)});
    }
    else
        mn = min({mn, rec(i + 1, j - 1), 1 + rec(i + 1, j), 1 + rec(i, j - 1)});
    return dp[i][j]=mn;
}
int solve()
{
    cin >> s;
    n = s.size();
    memset(dp, -1, sizeof(dp));
    return rec(0, n - 1);
}

int32_t main()
{
    FastFile();
    ll tc = 1;
    cin >> tc;
    for (ll i = 1; i <= tc; ++i)
    {
        cout << "Case "<<i<<": "<< solve() << endl;
        ;
    }
}
