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
    stack<int> nodes;
    set<pair<int, int>> ans;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        int x;
        cin >> x;
        if (s == "in")
        {
            if (nodes.size())
            {
                ans.insert({nodes.top(), x});
                nodes.push(x);
            }
        }
        else {
            nodes.pop();
        }
    }
    for(auto&it:ans){
        cout << it.first << " " << it.second << endl;
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
