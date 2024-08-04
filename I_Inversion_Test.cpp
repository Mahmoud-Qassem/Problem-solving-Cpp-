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

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), right(n);

    for (auto &it : v)
        cin >> it;
    int mn = INT_MAX;
    for (int i = n - 1; i >= 0; --i)
    {
        mn = min(mn, v[i]);
        right[i] = mn;
    }
    // for(auto&it:right)cout<<it<<" ";
    // cout<<endl;

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int idx = lower_bound(right.begin() + i, right.end(), v[i]) - right.begin();
        idx--;
        // cout << v[i] << " " << idx << endl;
        ans = max(ans, idx - i + 1);
    }
    cout << ans << endl;
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
