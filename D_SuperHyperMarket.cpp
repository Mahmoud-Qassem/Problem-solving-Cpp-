/*
* Created By Mahmoud Qassem
* You are free to use any time...
* Problem Link:
* 
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
    int n, k;
    cin >> n >> k;
    priority_queue<pair<pair<double, int>, double>, vector<pair<pair<double, int>, double>>, greater<pair<pair<double, int>, double>>> q;
    int idx = 0;
    vector<double> cust(k,0);


    cout << fx(4);
    for (int i = 0; i < n;++i){
        double x;
        cin >> x;

        if(idx<k){
            idx++;
            cout << idx << " ";
            q.push({{x, idx},x});
            cust[idx]+=1;
        }

        else{

            pair<pair<double, int>, double> tp = q.top();
            q.pop();

            int id = tp.first.second;
            double lst = tp.second;

            cout << id << " ";
            
            cust[id]+=1;

            double ci = cust[id];
            double p =(lst + x) / 2.0;
            double cip=ci * p;
            // cout <<x<<" "<< id << " " << cip <<" "<<lst<< endl;

            q.push({{cip, id}, x}); 
        }
    }
    cout << endl;
}

int32_t main() {
    FastFile();
    ll tc=1;
//    cin>>tc;
    for(ll i=1; i<=tc; ++i) {
        solve();
    }

}
