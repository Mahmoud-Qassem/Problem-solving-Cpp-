/*
 * Created By Mahmoud Qassem
 * You are free to use any time...
 * Problem Link:
 * https://vjudge.net/contest/638567#problem/E
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
int n;
vector<int> v;
int maxOf[11][50];
int rec(int idx, int last)
{
    if (idx >= n)
        return 0;

    if (~maxOf[idx][last])
        return maxOf[idx][last];

    if (v[idx] > last)
    {
        return maxOf[idx][last] = max(1 + rec(idx + 1, v[idx]), rec(idx + 1, last));
    }

    return maxOf[idx][last] = rec(idx + 1, last);
}
void solve()
{
    cin >> n;
    v = vector<int>(n);
    for (auto &it : v)
        cin >> it;

    // int maxOf[20][20];
    memset(maxOf, -1, sizeof(maxOf));
    cout << rec(0, 0) << endl;
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
