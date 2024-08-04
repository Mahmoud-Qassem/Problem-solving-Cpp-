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
const int MAX = 100001;
ll n, w;
ll maxOf[101][MAX];

vector<pair<ll, ll>> v;
ll SOLVE(ll idx, ll crntPrice)
{
    if (crntPrice < 0)
        return INT_MAX;

    if (idx >= n){
        if(!crntPrice)
        return 0;

        return INT_MAX;
    }

    if (~maxOf[idx][crntPrice])
    {
        return maxOf[idx][crntPrice];
    }

    // take the currnet element
    ll tmp = v[idx].first + SOLVE(idx + 1, crntPrice - v[idx].second);

    // leave the currnet element
    tmp = min(SOLVE(idx + 1, crntPrice), tmp);
    maxOf[idx][crntPrice] = tmp;

    return maxOf[idx][crntPrice];
}

void solve()
{
    cin >> n >> w;
    v.resize(n);
    int totalPrice = 0;
    memset(maxOf, -1, sizeof(maxOf));

    for (int i = 0; i < n; ++i)
        cin >> v[i].first >> v[i].second, totalPrice += v[i].second;
    
    for (int i = totalPrice; i >= 0; --i)
    {
        ll CW = SOLVE(0, i);
        // cout << i << " " << CW << endl;
        if (CW <= w)
        {
            cout << i << endl;
            return;
        }
    }
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
