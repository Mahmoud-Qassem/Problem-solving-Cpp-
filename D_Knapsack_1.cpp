#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(s) (s).begin(),(s).end()
#define allr(s) (s).rbegin(),(s).rend()
#define T int t;cin>>t;while(t--)
#define OO INT_MAX
#define fx(x) fixed << setprecision(x)
#define mod 1000000007
void FastFile() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
//    freopen("input.txt", "r", stdin);
//    freopen("OOO.txt", "w", stdout);
}
const int MAX = 100001;
ll n, w;
ll maxOf[101][MAX];

vector<pair<ll, ll>> v;
ll SOLVE(ll idx,ll space){
    if(space<0)
        return -1e9;

    if(idx>=n)
        return 0;
    
    if(~maxOf[idx][space]){
        return maxOf[idx][space];
    }



    // take the currnet element
    ll tmp = v[idx].second+SOLVE(idx + 1, space-v[idx].first);

    // leave the currnet element 
    tmp=max(SOLVE(idx + 1, space),tmp);
    maxOf[idx][space] = tmp;
    
    return maxOf[idx][space];
}

void solve(){
    cin >> n >> w;
    v.resize(n);
    memset(maxOf, -1, sizeof(maxOf));

    for (int i = 0; i < n;++i)
        cin >> v[i].first >> v[i].second;

    cout << SOLVE(0, w) << endl;
    
}

int32_t main() {
    FastFile();
    ll tc=1;
//    cin>>tc;
    for(ll i=1; i<=tc; ++i) {
        solve();
    }

}
