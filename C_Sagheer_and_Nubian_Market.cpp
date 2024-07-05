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
    ll n, S;
    cin >> n >> S;
    vector<pair<ll, ll>> v(n);

    for (int i = 0; i < n; ++i)
        cin >> v[i].first, v[i].second = i + 1;


    auto valid = [&](ll factorK)
    {
        vector<ll> tmp(n,0LL);
        for (int i = 0; i < n; ++i)
        {
            tmp[i] += v[i].first + (i + 1) * factorK;
        }

        sort(all(tmp));
        ll currentCost = 0;
        for (ll i = factorK - 1; i >= 0; --i)
        {
            currentCost += tmp[i];
            if (currentCost > S)
                return 0;
        }
        return 1;
    };

    ll left = 0, right = n, ans = 0, factorK;
    while (left <= right)
    {
        factorK = left + (right - left) / 2;
        if (valid(factorK))
        {
            left = factorK + 1;
            ans = factorK;
        }
        else
        {
            right = factorK - 1;
        }
    }
    vector<ll> tmp(n);

    for (int i = 0; i < n; ++i)
    {
        tmp[i] += v[i].first + (i + 1) * ans;
    }
    sort(all(tmp));

    ll currentCost = 0;
    for (ll i = ans - 1; i >= 0; --i)
    {
        currentCost += tmp[i];
    }

    cout << ans << " " << currentCost << endl;
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
