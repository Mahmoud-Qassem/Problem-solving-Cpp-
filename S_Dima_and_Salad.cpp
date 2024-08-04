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
// X/Y = CK
// X=Ck*Y
const int MAX = 101;
int n, k;
vector<pair<int, int>> v;
int dp[MAX][MAX * MAX*2];

int rec(int idx, int asum, int bsum)
{

    // cout << idx << " " << asum << " " << bsum << endl;
    if (idx >= n)
    {
        // if(bsum)
        // cout << "k " << asum / bsum << endl;
        if (bsum and asum % bsum == 0 and asum / bsum == k)
        {
            return asum;
        }
        return -1e7;
    }

    if (~dp[idx][asum])
    {
        return dp[idx][asum];
    }

    // take the current fruit
    int mx = rec(idx + 1, asum + v[idx].first, bsum + v[idx].second);
    // leave the current fruit
    mx = max(mx,rec(idx + 1, asum, bsum));

    return dp[idx][asum] = mx;
}

void solve()
{
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    v = vector<pair<int, int>>(n);
    for (auto &it : v)
        cin >> it.first;

    for (auto &it : v)
        cin >> it.second;
    int ans = rec(0, 0, 0);

    cout << (ans == -1e7 ? -1 : ans) << endl;
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
