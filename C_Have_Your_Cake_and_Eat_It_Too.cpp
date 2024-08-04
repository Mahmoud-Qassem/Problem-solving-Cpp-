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
void FastFile() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("OOO.txt", "w", stdout);
}


int n;
ll k;
bool cal(vector<ll>&p,vector<ll>&pp,vector<ll>&ppp,string s) {

    for(int i=1; i<=n; ++i) {
        ll x=p[i];
        if(x<k)continue;
        int idx=upper_bound(pp.begin()+1,pp.begin()+n+1,k+pp[i])-pp.begin();
        int cnt=10;
        while(cnt-- and idx>i+1 and pp[idx]-pp[i-1]>=k){
            idx--;
        }
        idx++;
        if(idx==n)continue;

        ll y=pp[idx]-pp[i-1];
        if(y<k)continue;
        ll z=ppp[n]-ppp[idx-1];
        if(z<k)continue;
        vector<pair<int,int>>ans(4),res(3);
        ans[0]={1,i};
        ans[1]={i+1,idx};
        ans[2]={idx+1,n};

        for(int j=0;j<3;++j){
            res[s[j]-'0'-1]=ans[j];
        }
        for(auto&it:res)cout<<it.first<<" "<<it.second<<" ";cout<<endl;
        return 1;
    }

    return 0;
}
void solve() {
    cin>>n;
    vector<int>v(n);
    vector<ll>p(n+2),pp(n+2),ppp(n+2);
    k=0;

    for(auto&it:v)cin>>it,k+=it;
    for(int i=1; i<=n; ++i) {
        p[i]+=p[i-1]+v[i-1];
    }

    for(auto&it:v)cin>>it;
    for(int i=1; i<=n; ++i) {
        pp[i]+=pp[i-1]+v[i-1];
    }


    for(auto&it:v)cin>>it;
    for(int i=1; i<=n; ++i) {
        ppp[i]+=ppp[i-1]+v[i-1];
    }

//    for(int i=n; i>0; --i) {
//        ppp[i]+=ppp[i+1]+v[i-1];
//    }
//    reverse(all(ppp));

    k/=3;

    if(cal(p,pp,ppp,"123"))return ;
    if(cal(p,ppp,pp,"132"))return ;

    if(cal(pp,p,ppp,"213"))return ;
    if(cal(pp,ppp,p,"231"))return ;

    if(cal(ppp,pp,p,"321"))return ;
    if(cal(ppp,p,pp,"312"))return ;


    cout<<-1<<endl;






}

int32_t main() {
//    FastFile();
    ll tc = 1;
    cin >> tc;
    for (ll i = 1; i <= tc; ++i) {
        solve();
    }
}





/*


int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    vector<vector<int>>b(n,vector<int>(m));
    for(auto&it:a)
        for(auto&ic:it)cin>>ic;
    for(auto&it:b)
        for(auto&ic:it)cin>>ic;


    for(int i=n-2;i>=0;--i){
        for(int j=0;j<n-1;++j){
            int A00=a[i][j];
            int A01=a[i+1][j+1];

            int A02=a[i+1][j];
            int A03=a[i][j+1];

            int B00=b[i][j];
            int B01=b[i+1][j+1];

            int B02=b[i+1][j];
            int B03=b[i][j+1];

            if(A01==B01 and A02==B02){
                continue;
            }








        }
    }


    */








