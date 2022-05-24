// 给定一个三角形 triangle ，找出自顶向下的最小路径和。
// 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
// 也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

//解法1：
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        if(triangle.size() == 0){
            return 0;
        }

        std::vector<std::vector<int>> dp;

        for(int i = 0; i < triangle.size(); i++){
            dp.push_back(std::vector<int>());
            for(int j = 0; j < triangle[i].size(); j++){//这里得是triangle[i].size() ,不能是triangle.size()
                dp[i].push_back(0);
            }
        }

        for(int i = 0; i < dp.size(); i++){
            dp[dp.size() - 1][i] = triangle[dp.size() - 1][i]; 
        }

        for(int i = dp.size() - 2; i >= 0; i--){//从倒数第二层开始
            for(int j = 0; j < dp[i].size(); j++)
                dp[i][j] = std::min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
        }
        return dp[0][0];
        

    }
};
