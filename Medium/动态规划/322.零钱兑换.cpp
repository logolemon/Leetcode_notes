//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
//你可以认为每种硬币的数量是无限的

//解法1：
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp;
        for(int i = 0; i <= amount; i++){
            dp.push_back(-1);//最初所有金额的最优解均为-1（不可达到）
        }
        dp[0] = 0;//金额0最优解0 递推
        for(int i = 1; i <= amount; i++){//循环各个面值，找到dp[i]最优解
            for(int j = 0; j < coins.size(); j++){
                if( i - coins[j] >= 0 && dp[i - coins[j]] != -1){//前面的金额可以达到，并且包括有这种面值的钞票
                    if(dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1){
                        dp[i] = dp[i - coins[j]] + 1;
                    }
                }
            }
        }
        return dp[amount];

    }
};
