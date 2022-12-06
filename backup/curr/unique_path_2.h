//https://leetcode.com/problems/unique-paths-ii/
#include <vector>
#include <iostream>
using namespace std;

class Solution {    
public:    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {    
        int m = obstacleGrid.size();    
        int n = obstacleGrid[0].size();    
        
        vector<vector<int>> dp (m, vector<int>(n,-1));
        return countPaths(obstacleGrid, dp, n-1, m-1, n, m);    
    }                                                           
         
    bool check_limit(int i, int j, int n, int m) {    
        if (i >= n) return false;    
        if (i < 0)  return false;    
        if (j >= m) return false;        
        if (j < 0)  return false;    
        return true;    
    }    
         
    int countPaths(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int i, int j, int n, int m) {            
        if (dp[j][i] != -1) {
            return dp[j][i];
        }
        if (obstacleGrid[j][i]) {
            dp[j][i] = 0;
            return 0;
        }
        if (i == 0 && j == 0) {   
            dp[j][i] = 1;
            return 1;
        }
        int path_count = 0;    
        if (check_limit(i-1,j,n,m) && !obstacleGrid[j][i-1]) {   
            path_count = countPaths(obstacleGrid, dp, i-1, j, n, m);
        }    
        if (check_limit(i,j-1,n,m) && !obstacleGrid[j-1][i]) {
            int up_path = countPaths(obstacleGrid, dp, i, j-1, n,m);
            path_count = path_count + up_path;
            
        }
        dp[j][i] = path_count;
        return path_count;        
    }    
};
