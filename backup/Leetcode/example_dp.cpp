
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp (m, vector<int>(n,-1));
        int ans = 1;

        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                ans = max(ans, func(matrix, dp, i, j, n, m));      
            }
        }

        return ans;
    }

    bool check_limit(int i, int j, int n, int m) {
        if (i >= 0 && i < n && j >= 0 && j < m) {
            return true;
        } else {
            return false;
        }
    }

    int func(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int n, int m) {
        if (!check_limit(i,j,n,m)) {
            return 0;
        }
        if (dp[j][i] != -1) {
            return dp[j][i];
        }

        
        int max = 0;
        if (check_limit(i,j-1,n,m) && matrix[j][i] < matrix[j-1][i]) {
            max = std::max(max,func(matrix, dp, i, j-1, n, m));
        }
        if (check_limit(i,j+1,n,m) && matrix[j][i] < matrix[j+1][i]) {
            max = std::max(max,func(matrix, dp, i, j+1, n, m));
        }
        if (check_limit(i-1,j,n,m) && matrix[j][i] < matrix[j][i-1]) {
            max = std::max(max,func(matrix, dp, i-1, j, n, m));
        }
        if (check_limit(i+1,j,n,m) && matrix[j][i] < matrix[j][i+1]) {
            max = std::max(max,func(matrix, dp, i+1, j, n, m));
        }
            
        dp[j][i] = max + 1;
        return dp[j][i];
    }
};
