// 已知一个二维数组，其中存储了非负整数，找到从左上角到右下角的一条路径，使得路径上的和最小。(移动过程中只能向下或向右)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return 0;
        }

        std::vector<std::vector<int>> dp;
        for(int i = 0; i < grid.size(); i++){
            dp.push_back(std::vector<int>());
            for(int j = 0; j < grid[i].size(); j++){
                dp[i].push_back(0);
            }
        }

        dp[0][0] = grid[0][0];

        for(int i = 1; i < grid[0].size(); i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for(int i = 1; i < grid.size(); i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
            
            for(int j = 1; j < grid[0].size(); j++){
                dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[grid.size() - 1][grid[0].size() - 1];

    }
};

// 解法2：就构造dp[][]数组的方式不一样，这种方法清晰明了一点
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return 0;
        }

        int row = grid.size();
        int column = grid[0].size();
        std::vector<std::vector<int>> dp(row, std::vector<int>(column,0));

        dp[0][0] = grid[0][0];

        for(int i = 1; i < column; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for(int i = 1; i < row; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
            
            for(int j = 1; j < column; j++){
                dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[row-1][column-1];
    }
};

