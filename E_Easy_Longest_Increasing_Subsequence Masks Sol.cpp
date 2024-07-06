/*
* Created By Mahmoud Qassem
* You are free to use any time...
* Problem Link:
* https://vjudge.net/contest/638567#problem/E
*/
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
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto&it:v)
        cin >> it;

    int mxSubseqSize = 0;
    for (int i = 0; i < (1 << n);++i){
        bitset<11> bits(i);
        vector<int> increasingSubseq;
        // int lst = -1;
        for (int j = 0; j < n;++j){
            if(bits[j]){
                // cout << v[j] << " ";
                increasingSubseq.push_back(v[j]);
            }
        }
        // cout << endl;
        bool ok = 1;
        for (int j = 1; j < increasingSubseq.size();++j){
            ok &= (increasingSubseq[j - 1] < increasingSubseq[j]);
        }
        ok ? mxSubseqSize = max((int)increasingSubseq.size(), mxSubseqSize):1;
    }
    cout << mxSubseqSize << endl;
    
    
}

int32_t main() {
    FastFile();
    ll tc=1;
//    cin>>tc;
    for(ll i=1; i<=tc; ++i) {
        solve();
    }

}
