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

bool palind(string s)
{
    int n = s.size();
    for (int i = 0; i <= n / 2; ++i)
        if (s[i] != s[n - i - 1])
            return 0;
    return 1;
}
void solve()
{
    string s;
    cin >> s;
    bool pal = 0;
    int n = s.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < min(n, i + 3); ++j)
        {
            string ss = s.substr(i, j - i + 1);
            if (palind(ss))
            {
                cout << "yes" << endl;
                
                return;
            }
        }
    }
    cout << "no" << endl;
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
