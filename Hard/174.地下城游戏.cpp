// 数组、动态规划、矩阵

// 解法1：
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.size() == 0){
            return 0;
        }

        int row = dungeon.size();
        int column = dungeon[0].size();
        

        std::vector<std::vector<int>> dp(row, std::vector<int>(column, 0));//dp数组的构造得清楚

        dp[row-1][column-1] = std::max(1, 1-dungeon[row-1][column-1]);//初始化条件得写正确

        for(int j = row - 2; j >= 0; j--){//这个地方得循环到最上面一行所有是 j >= 0 而不应该是 j > 0
            dp[j][column-1] = std::max(1,dp[j+1][column-1] - dungeon[j][column-1]);
        }

        for(int i = column-2; i >= 0;i--){
            dp[row-1][i] = std::max(1,dp[row-1][i+1] - dungeon[row-1][i]);//注意这个地方的下标是dp[row-1][i+1]
        } 

        for(int i = row -2; i >= 0; i--){
            for(int j = column - 2; j >= 0; j--){
                int dp_min = std::min(dp[i+1][j] - dungeon[i][j], dp[i][j+1] - dungeon[i][j]);//注意定义dp_min
                dp[i][j] = std::max(1, dp_min);
            }
        }
        return dp[0][0];
    }
};
