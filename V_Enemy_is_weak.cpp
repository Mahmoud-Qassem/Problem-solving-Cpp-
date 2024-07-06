#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(), (v).end()
#define nn cout << "\n"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class type1>
using ordered_multiset = tree<type1, null_type, less_equal<type1>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_multiset<ll> os;

void Ahmed_Sayed()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
// sssssssssss
int main()
{
    Ahmed_Sayed();
    ll n;
    cin >> n;
    ll ans = 0;
    vector<ll> x(n), suf(n + 1);
    for (auto &i : x)
        cin >> i;

    for (int i = n - 1; i >= 0; i--)
    {
        suf[i] = os.order_of_key(x[i]);
        os.insert(x[i]);
    }
    os.clear();

    for (int i = 0; i < n; i++)
    {
        // cout << os.size() << " " << os.order_of_key(x[i]) << " " << suf[i] << endl;
        //       greater than me on right * smaller than me on left
        ans += (os.size() - os.order_of_key(x[i])) * suf[i];
        os.insert(x[i]);
    }
    cout << ans;
}
