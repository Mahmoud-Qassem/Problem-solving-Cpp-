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
// X/Y = CK
// X=Ck*Y
const int MAX = 111;
int n, k;
int a[MAX],b[MAX],dp[MAX][MAX*MAX*MAX/5];
int rec(int idx,int delta){
    if(idx==n)
        return delta ? -1e9 : 0;
    
    if(~dp[idx][delta])
        return dp[idx][delta];

    return dp[idx][delta] = max(rec(idx + 1, delta), a[idx] + rec(idx + 1,delta + a[idx] - k * b[idx]));
}


void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for (int i = 0; i < n;++i)
        cin >> a[i];

    for (int i = 0; i < n;++i)
        cin >> b[i];

    cout<<(rec(0,0)>0?rec(0,0):-1)<<endl;
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
