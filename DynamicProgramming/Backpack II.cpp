class Solution {
public:
    /*
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int n = A.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (j >= A[i - 1]) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - A[i - 1]] + V[i - 1]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }
};
