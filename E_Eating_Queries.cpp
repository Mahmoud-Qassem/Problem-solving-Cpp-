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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);

    for (auto &it : v)
        cin >> it;
    sort(allr(v));
    vector<ll> pref(n + 2);
    for (int i = 1; i <= n; ++i)
    {
        pref[i] += pref[i - 1] + v[i - 1];
    }
    while (m--)
    {
        ll x;
        cin >> x;
        int idx = lower_bound(pref.begin() + 1, pref.begin() + n, x) - pref.begin();
        if(idx<=n and pref[idx]>=x)
        cout << idx << endl;
        else
            cout << -1 << endl;
    }
}

int32_t main()
{
    FastFile();
    ll tc = 1;
       cin>>tc;
    for (ll i = 1; i <= tc; ++i)
    {
        solve();
    }
}
