// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

// 解法1：自己写的方法，运用dp，但是超出了时间限制
// 转移方程：只有卖出和不卖出两种可能，设dp[i]表示以第i个数结尾的最大差值(最大利润)
// 卖出：prices[i] - 前面最小的价格
// 不卖：dp[i-1]
// dp[i] = max(dp[i-1], prices[i] - min(price[0:i]));
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size() == 0 || prices.size() == 1){
            return 0;
        }

        int n = prices.size();

        std::vector<int> dp(n,0);//定义一个dp数组，dp[i]表示以第i个价格数字结尾的最大利润(也就是最大差值)
        dp[0] = 0;//初始化条件

        for(int i = 1; i < n; i++){
          
            int min_price = prices[0];
            for(int j = 0; j < i ;j++){ //
                if(min_price > prices[j+1]){
                    min_price = prices[j+1];
                }        
            }
          
            dp[i] = std::max(dp[i-1], prices[i] - min_price);
                
        }

        return dp[n-1];

    }
};

// 解法2：动态规划思想，
// 执行用时：112 ms, 在所有 C++ 提交中击败了42.22%的用户
// 内存消耗：90.9 MB, 在所有 C++ 提交中击败了99.08%的用户
// 找到历史的最小值，也就是最低的价格，然后每天所需要考虑的事就是今天的价格和历史最低价格相比较，可以盈利多少，然后看哪天盈利的最多
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;//这里是10^9次方
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};

// 解法3：也就是解法2的上一个版本，这个版本也是动态规划，只是没有考虑空间优化方面的问题
// 执行用时：120 ms, 在所有 C++ 提交中击败了29.38%
// 内存消耗：95 MB ，在所有C+＋提交中击败了 16.46%的用户

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()){
            return 0;
        }

        int max = 0;
        vector<int> dp(prices.size(),0);//dp[i]表示截止到i，价格的最低点是多少   dp[i]=min(dp[i-1],nums[i])
        dp[0] = prices[0];//
        for(int i = 1; i < prices.size(); i++){
            if(dp[i-1] < prices[i]){//这个if语句的作用就类似在记录历史的最小价格
                dp[i] = dp[i-1];
            }
            else{
                dp[i] = prices[i];
            }

            max = (prices[i] - dp[i]) > max ? prices[i] - dp[i] : max;
        }

        return max;
    }
};



