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
const int MAX = 100100;
int n;
vector<vector<int>> v;
int maxOf[MAX][4];

int rec(int idx,int lst=3){
    if(idx>=n)
        return 0;
    if(maxOf[idx][lst]!=-1)
        return maxOf[idx][lst];

    int one = 0, two = 0, three = 0;
    if(lst!=0){
        one = v[idx][0]+rec(idx + 1, 0);
    }
    if(lst!=1){
        two = v[idx][1]+rec(idx + 1, 1);
    }
    if(lst!=2){
        three = v[idx][2]+rec(idx + 1,2);
    }

    return maxOf[idx][lst]=max({one,two,three});
}
void solve(){
    // int n;
    memset(maxOf,-1,sizeof(maxOf));
    cin >> n;
    v.resize(n, vector<int>(3));
    // maxOf.resize(n, vector<int>(4));
    for(int i =0;i<n;++i){
        for (int j = 0; j < 3;++j){
            cin >> v[i][j];
            // maxOf[i][j] = -1;
        }
    }
    cout << rec(0, 3) << endl;
}

int32_t main() {
    FastFile();
    ll tc=1;
//    cin>>tc;
    for(ll i=1; i<=tc; ++i) {
        solve();
    }

}
