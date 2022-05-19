class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];

        int max_res = dp[0];

        for(int i = 1; i< nums.size(); i++){
            dp[i] = std::max(nums[i], dp[i-1] + nums[i]);
            if(max_res < dp[i]){//这个地方要比较的原因就是 我们要求的是这个数组最大的和 所以需要拿第一个和dp[i]作一下比较
                max_res = dp[i];
            }
        }
        return max_res;

    }
};
