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

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> b(m),a(n);
    for(auto&it:a)
        cin >> it;

    for(auto&it:b)
        cin >> it;

    sort(all(a));

    for (int i = 0; i < m;++i){
        int value = b[i];
        int idx = upper_bound(all(a), value) - a.begin();
        cout << idx << " ";
    }
}

int32_t main() {
    FastFile();
    ll tc=1;
//    cin>>tc;
    for(ll i=1; i<=tc; ++i) {
        solve();
    }

}
