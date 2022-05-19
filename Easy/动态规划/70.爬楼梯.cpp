class Solution {
public:
    int climbStairs(int n) {
            std::vector<int> dp(n+3, 0);//这里采用的是n + 3；目的是为了让n = 0、n = 1、n = 2也可以走下面的for循环这些语句 
            dp[1] = 1;
            dp[2] = 2;

            for(int i = 3; i <= n; i++){
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
    }
};
