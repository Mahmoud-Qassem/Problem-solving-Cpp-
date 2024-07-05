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
    vector<ll> needed(n), have(n);
    for (auto &it : needed)
        cin >> it;

    for (auto &it : have)
        cin >> it;

    auto valid = [&](ll mid)
    {
        ll tmp = k;
        for (ll i = 0; i < n; ++i)
        {
            if (have[i] / needed[i] < mid)
            {
                if (tmp < mid * needed[i] - have[i])
                {
                    return 0;
                }
                else
                {
                    tmp -= mid * needed[i] - have[i];
                }
            }
        }
        return 1;
    };

    ll left = 0, right = 2000000000, ans = 0, mid;
    ;
    while (left <= right)
    {
        // cout << mid << endl;
        mid = left + (right - left) / 2;
        if (valid(mid))
        {
            // cout<<mid << " valid" << endl;
            left = mid + 1;
            ans = mid;
        }
        else
            right = mid - 1;
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
