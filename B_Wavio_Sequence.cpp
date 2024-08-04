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
void FastFile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("OOO.txt", "w", stdout);
}
class Solution {
public:
    vector<int>lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size()+1,INT_MAX);
        int len=0;
        dp[0]=INT_MIN;
        vector<int>ret(nums.size());
        for(int i=0; i<nums.size(); i++) {
            auto lb=lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            if(dp[lb-1]<=nums[i] and nums[i]<=dp[lb]) {
                ret[i]=lb;
                dp[lb]=nums[i];
            }
        }
//        for(int i=1;i<nums.size();++i)if(!ret[i])ret[i]=ret[i-1];
        return ret;
    }
};
int32_t main()
{
    FastFile();
    Solution ob;

    int n;
    while (cin >> n and n != EOF)
    {
        int ans = 0;
        vector<int> v(n), v1, v2;
        for (auto &it : v)
            cin >> it;

        v1 = ob.lengthOfLIS(v);
        reverse(all(v));
        v2 = ob.lengthOfLIS(v);
        reverse(all(v2));
        for (int i = 0; i < n; ++i)
        {
            if (v1[i] and v2[i])
            {
                if (v1[i] == v2[i])
                {
                    ans = max(ans, v1[i] * 2 - 1);
                }
                else
                {
                    ans = max(ans, min(v1[i], v2[i]) * 2 - 1);
                }
            }
        }
        cout << ans << endl;
    }
}
/*
hints for dp
when you thinks that the problem can be solved with dp
you may ask yourself what should I dp for
the max of something
the min of something
the count of something
and then choose the parameters of the dp to DISTINGUISH the states of the dp
*/
