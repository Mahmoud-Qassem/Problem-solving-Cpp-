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
ll n;
vector<ll> cost;
vector<pair<string, string>> v;
ll id = 1e17;
map<pair<ll, string>, ll> dp;
map<pair<ll, string>, bool> visited;

ll rec(ll idx, string last)
{
    // cout << last << endl;
    if (idx >= n)
        return 0;
    string crnt = v[idx].first, rev = v[idx].second;
    if(crnt<last and rev<last)
        return 1e17;

    auto &ret = dp[{idx, last}];
    if(visited[{idx,last}])
        return ret;

    ll mn = 1e18;
    if(crnt>=last){
        mn = min(mn, rec(idx + 1, crnt));
    }
    if(rev>=last)
        mn = min(mn, cost[idx]+rec(idx + 1, rev));

    visited[{idx, last}] = 1;
    return dp[{idx,last}]=mn;
}
void solve()
{
    cin >> n;
    cost.resize(n);
    for (auto &it : cost)
        cin >> it;
    v.resize(n);
    for (auto &it : v)
    {
        cin >> it.first;
        it.second = it.first;
        reverse(all(it.second));
    }
    ll ans=rec(0, string((ll)v[0].first.size(), 'a'));
    cout << (ans > 1e14*1LL ? -1 : ans) << endl;
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
