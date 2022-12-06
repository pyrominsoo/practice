//https://leetcode.com/problems/unique-paths-ii/
#include <vector>
#include <iostream>

using namespace std;

class Solution {    
public:    
    int uniquePathsWithObstacles(std::vector<vector<int>>& obstacleGrid) {    
        int m = obstacleGrid.size();    
        int n = obstacleGrid[0].size();    
            
        return countPaths(obstacleGrid, n-1, m-1, n, m);    
    }                                                           
         
    bool check_limit(int i, int j, int n, int m) {    
        if (i >= n) return false;    
        if (i < 0)  return false;    
        if (j >= m) return false;        
        if (j < 0)  return false;    
        return true;    
    }    
         
    int countPaths(vector<vector<int>>& obstacleGrid, int i, int j, int n, int m) {            
        int path_count = 0;    
        if (i == 0 && j == 0)   
            std::cout << "base 1" << endl;
            return 1;            
        if (check_limit(i-1,j,n,m) && !obstacleGrid[j][i-1]) {   
            path_count = countPaths(obstacleGrid, i-1, j, n, m);
            std::cout << "Count left = " << path_count << endl;
        }    
        if (check_limit(i,j-1,n,m) && !obstacleGrid[j-1][i]) {
            int up_path = countPaths(obstacleGrid, i, j-1, n,m);
            std::cout << "Count right = " << up_path << endl;
            path_count = path_count + up_path;
            
        }
        cout << "Return = " << path_count << endl;
        return path_count;        
    }    
};
