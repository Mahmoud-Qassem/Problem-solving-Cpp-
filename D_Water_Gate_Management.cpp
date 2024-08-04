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

int n, id = 1;
ll V, H;
vector<pair<int, int>> gates;
map<pair<int, int>, long long> dp;

map<pair<int, int>, short> visited;

ll rec(int idx, int rem)
{
    if (idx >= n)
        if (rem > 0)
            return 1e15;
        else
            return 0LL;

    if (visited[{idx, rem}] == id)
        return dp[{idx, rem}];
        
    ll mn = 1e16;

    mn = min(mn, gates[idx].second + rec(idx + 1, rem - (H * gates[idx].first)));
    mn = min(mn, rec(idx + 1, rem));

    visited[{idx, rem}] = id;
    return dp[{idx, rem}] = mn;
}
void solve()
{
    id++;
    cin >> V >> H;
    ll tmp = rec(0, V);
    if (tmp == 1e15)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << tmp << endl;
}

int32_t main()
{
    FastFile();
    int tc = 1;
    cin >> n;
    gates = vector<pair<int, int>>(n);
    for (auto &it : gates)
        cin >> it.first >> it.second;
    cin >> tc;
    for (int i = 1; i <= tc; ++i)
    {
        cout << "Case " << i << ": ";
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
