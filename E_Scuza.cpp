#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef unsigned long long int  ull;
#define T  int tests; cin >> tests;while (tests--)
#define vi vector<int>
#define vl vector<ll>
#define endl '\n'
#define here cout<<"here"<<endl;
#define pi 3.141592653589793
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define filll(c,n,k)  cout<<setfill(c)<<setw(n)<<k;
#define pb push_back
#define F first
#define S second
#define OO 1e12
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
void File()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
void Fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll n;
vector<ll>v;
bool right(ll i)
{
    ll cur=i;
    while(cur<n)
    {
        cur+=v[cur]+1;
    }
    return cur==n;
}
bool left(ll i)
{
    ll cur=i;
    while(cur>=0)
    {
        cur-=(v[cur]+1);
    }
    return cur == -1;
}

int32_t main()
{
    Fast();
    T
    {
        ll n,q,mx=0;
        cin>>n>>q;
        vector<ll>v(n);
        for(int i=0;i<n;++i)
        {
            cin>>v[i];
        }
        ll cur=0;
        vector<ll>sum(n+5);
        for(int i=1;i<=n;++i)
        {
            cur+=v[i-1];
            sum[i]=cur;
        }
        for(int i=0;i<n;++i)
        {
            mx=max(mx,v[i]);
            v[i]=mx;
        }
        while(q--)
        {
            ll x;cin>>x;
            ll idx=upper_bound(all(v),x)-v.begin();
            cout<<sum[idx]<<" ";
        }
        cout<<endl;
    }


















}