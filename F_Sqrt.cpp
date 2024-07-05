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
    ll x,sq;
    cin >> x;
    ll left = 0, right = x;
    // auto valid = [&](ll mid)
    // {
    //     return 1;
    // };
   
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if(mid*mid<x){
            left = mid + 1;
        }
        else if(mid*mid>x){
            right = mid - 1;
        }
        else{
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    
}

int32_t main() {
    FastFile();
    ll tc=1;
//    cin>>tc;
    for(ll i=1; i<=tc; ++i) {
        solve();
    }

}
