/*
 * Created By Mahmoud Qassem
 * You are free to use any time...
 * Problem Link:
 * https://vjudge.net/contest/638567#problem/J
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
const int MAX = 100;
int dp[MAX][MAX * 500];
vector<int> v;
int sum = 0, n;

int rec(int idx, int cnt = 0)
{
    if (idx >= n)
    {
        // cout << sum << " " << cnt << endl;
        return abs(cnt-abs(sum - cnt));
    }

    if (~dp[idx][cnt])
    {
        return dp[idx][cnt];
    }

    // take
    int mn = INT_MAX;
    mn = min(mn, rec(idx + 1, cnt + v[idx]));
    mn = min(mn, rec(idx + 1, cnt));

    return dp[idx][cnt] = mn;
}
void solve()
{
    cin >> n;
    v = vector<int>(n);
    sum = 0;
    for (auto &it : v)
        cin >> it, sum += it;

    memset(dp, -1, sizeof(dp));

    cout << rec(0) << endl;
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
