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

const ll MAX = 200200;
ll F[MAX];
void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);

    for (auto &it : v)
        cin >> it, F[it]++;

    sort(all(v));

    ll mex;

    for (ll i = 0; i <= n + 2; ++i) {
        if (not F[i]) {
            mex = i;
            break;
        }
    }


    ll crntCost = 0;
    stack<ll> add;
    bool flag=0;

    for (ll i = 0; i <= n; ++i) {
        if (i < mex) {
            cout << F[i] << " ";
            F[i]--;
            while (F[i]--)
                add.push(i);
        }

        else if (i == mex) {
            cout << 0 << " ";
            if (add.size())
                crntCost += (i - add.top()), add.pop();
            else flag=1;
        }

        else if(flag) {
            cout<<-1<<" ";
        }

        else if(F[i]) {
            crntCost+=F[i];
            F[i+1]+=F[i];
            cout<<crntCost<<" ";

            crntCost--;
            F[i+1]--;

        }

        else {
            cout<<crntCost<<" ";

            if (!add.size()) {
                flag=1;
            } else {
                crntCost+=(i-add.top()),add.pop();
            }
        }
        F[i]=0;
    }
    cout << endl;
}

int32_t main() {
    FastFile();
    ll tc = 1;
    cin >> tc;
    for (ll i = 1; i <= tc; ++i) {
        solve();
    }
}
