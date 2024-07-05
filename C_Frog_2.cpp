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
const int MAX = 100100;
int n, k;
vector<int> v;
int maxOf[MAX][101];

int rec(int idx, int lst)
{
    if (idx == n - 1)
        return 0;
    if (maxOf[idx][lst] != -1)
        return maxOf[idx][lst];

    maxOf[idx][lst] = 1e9+1;
    for (int i = 1; i <= k; ++i)
    {
        if (idx + i < n)
        {
            maxOf[idx][lst] =min(maxOf[idx][lst],abs(v[idx] - v[idx + i]) + rec(idx + i, i)) ;
        }
    }

    return  maxOf[idx][lst];
}
void solve()
{
    // int n;
    memset(maxOf, -1, sizeof(maxOf));
    cin >> n>>k;
    v.resize(n);
    // maxOf.resize(n, vector<int>(4));
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    cout << rec(0, k+1) << endl;
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
