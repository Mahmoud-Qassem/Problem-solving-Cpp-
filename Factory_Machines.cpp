#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(s) (s).begin(), (s).end()
#define allr(s) (s).rbegin(), (s).rend()
#define T     \
    ll t;    \
    cin >> t; \
    while (t--)
#define OO ll_MAX
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
    ll n, k;
    cin >> n >> k;

    vector<ll> machines(n);
    for (auto &it : machines)
        cin >> it;

    auto valid = [&](ll mid)
    {
        ll cnt = 0;
        for (ll i = 0; i < n; ++i)
        {
            cnt += (mid / machines[i]);
            if (cnt >= k)
                return 1;
        }
        return 0;
    };
    ll left = 0,
       right = 1e18, ans, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (valid(mid))
        {
            right = mid - 1;
            ans = mid;
        }
        else
            left = mid + 1;
    }
    cout << ans << endl;
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
