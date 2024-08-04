#include <iostream>
#include <vector>
using namespace std;

int countPalindromicSubsequences(string S)
{
    int N = S.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // Single character palindromes
    for (int i = 0; i < N; ++i)
    {
        dp[i][i] = 1;
    }

    // Fill the DP table
    for (int length = 2; length <= N; ++length)
    {
        for (int i = 0; i <= N - length; ++i)
        {
            int j = i + length - 1;
            if (S[i] == S[j])
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
            }
            else
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }

    // The result for the entire string
    return dp[0][N - 1];
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        cout << countPalindromicSubsequences(s) << endl;
    }
    return 0;
}
