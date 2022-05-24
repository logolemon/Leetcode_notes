// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
// 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

//解法1：
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }//如果数组为空，则返回0

        std::vector<int> dp(nums.size(), 0);//设置存放最长子序列数值的数组dp[]

        dp[0] = 1;//初始化边界条件

        int LIS = 1;

        for(int i = 1; i < dp.size(); i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
            if(LIS < dp[i]){
                LIS = dp[i];
            }
        }
        return LIS;
    }
};
