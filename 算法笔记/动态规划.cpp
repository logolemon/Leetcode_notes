//动态规划（Dynamic Programming）概述

//动态规划是运筹学的一个分支，是求解决策过程最优化的数学方法。最优化原理，它利用各阶段之间的关系，逐个求解，最终求得全局最优解。
//在设计动态规划算法时，需要确认原问题与子问题、动态规划状态、边界状态结值、状态转移方程等关键要素。

//在算法面试中，动态规划是最常考察的题型之一，大多数面试官都以否可较好的解决动态规划相关问题来区分候选是否"聪明"。

//例1：爬楼梯
//解法1：暴力搜索，回溯法
//这个方法，等n = 45 时，该方法是不可以提交leetcode的，原因就是超时了。
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2){
            return n;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

//思考：到达楼梯的第i阶有多少种爬法，与第几阶的爬法直接相关，如何递推的求出第i阶爬法数量？
//分析：由于每次最多爬2阶，楼梯的第i阶，只可能从楼梯的第i-1阶和第i-2阶到达，所以到达第i阶有多少种爬法，只与第i-1阶，第i-2阶的爬法数量直接相关
//第i阶的爬法数量 = 第i-1阶的爬法数量 + 第i-2阶的爬法数量
//算法思路：
//1.设置递推数组dp[0……n]，dp[i]代表的是到第i阶的爬法数量，就是有多少种走法，初始化数组为0
//2.设置到达第1阶台阶，有1种走法，到达第2阶台阶，有2种走法
//3.利用i循环递推从第3阶到第n阶的结果：到达第i阶的走法数量 = 到达第i-1阶的走法数量 + 到达第i-2阶的走法数量
//解法2：动态规划
class Solution {
public:
    int climbStairs(int n) {
            std::vector<int> dp(n+3, 0);
            dp[1] = 1;
            dp[2] = 2;

            for(int i = 3; i <= n; i++){
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
    }
};

//动态规划原理
//1.确认原问题和子问题
//原问题是求第n阶台阶所有走法的数量，子问题是求1阶台阶，2阶台阶、……、n-1阶台阶的走法数量
//2.确认状态：
//本题爬楼梯动态规划的状态单一，第i个状态就是为i阶台阶的所有走法数量
//3.确认边界状态的值：
//边界状态为1阶台阶与2阶台阶的走法，1阶台阶有1种走法，2阶台阶有两种走法，即dp[1] = 1; dp[2] = 2
//4.确认状态转移方程：
//将求第i个状态的值转移为求第i-1个状态值与第i-2个状态的值，动态规划转移方程，dp[i] = dp[i - 1] + dp[i - 2]
//-----------------------------------------------------------------------------------------------------------------------------------------------------

//例2：打家劫舍
//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
//如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//给定一个代表每个房屋存放金额的非负整数数组，计算你不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

//思考
//1.n个房屋，每个房间都有盗取/不盗取两种可能，类似求子集（暴力搜索）的方法，在不触发警报的情况下，选择总和最大的子集，最多有2^n种可能，时间复杂度O（2^n）
//是否有更好的方法？
//2.贪心算法是否可行？肯定不可行
//例如，在满足不触发警报的同时，每次选择财宝最多的房间，如[5,2,6,3,1,7],选择最大的7，6，5恰好是最佳答案。
//3.若考虑动态规划(dp)方法，如何确认dp原问题与子问题、状态、边界状态、状态转移方程？

//分析
//由于同时从相邻的两个房间中盗取财宝就会触发报警器，故：
//a.若选择第i个房间盗取财宝，就一定不能选择第i-1个房间盗取财宝
//b.若不选择第i个房间盗取财宝，则相当于只考虑前i-1个房间盗取财宝

//算法思路：
//1.确认原问题和子问题
//原问题为求n个房间的最优解，子问题为求前1个房间，前2个房间，……前n-1个房间的最优解。
//2.确认状态：
//第i个状态即为前i个房间能够获得的最大财宝（最优解）
//3.确认边界状态的值：
//前1个房间的最优解，第1个房间的财宝
//前2个房间的最优解，第1、2个房间中较大财宝
//4.确定状态转移方程
//a.选择第i个房间：第i个房间 + 前i-2个房间的最优解
//b.不选择第i个房间：前i-1个房间的最优解
//动态规划转移方程：dp[i] = max(dp[i-1], dp[i-2] + nums[i]);(i>=3)

//解法：
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[1], nums[0]);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[nums.size() - 1];//返回的是数组里面的最后一个元素

    }
};

//--------------------------------------------------------------------------------------------------------------------------------------------------------
//例3：最大子段和
//给定一个数组，求这个数组的连续子数组中，最大的那一段的和
//如数组[-2,1,-3,4,-1,2,1,-5,4]:
//连续子数组有很多，但是最大的子数组为[4,-1,2,1],和为6，我们就是得求这个6

//思考
//暴力枚举所有连续子段的和，复杂度是？枚举太过于复杂，肯定不予考虑
//若尝试动态规划方法，最关键的是确认动态规划状态，若假设第i个状态dp[i]代表前i个数字组成的连续的最大子段和，能否推导出dp[i]与dp[i-1]之间的关系呢？

//分析
//实际上，如果设第i个状态（dp[i]）代表前i个数字组成的连续的最大子段和，并不能根据dp[i-1], dp[i-2]……、dp[0]推导出dp[i].
//两者不相邻，故无法构成连续的子数组，之间无内在联系，故无法进行推导
//为了让第i个状态的最优解与第i-1个状态的最优解产生直接联系，思考：
//如果第i个状态（dp[i]）代表以第i个数字结尾的最大子段和，那么dp[i]与dp[i-1]之间的关系是什么？如何根据dp[i-1]推导出dp[i]？这样推导又如何求得最终的结果？

//算法思路
//将求n个数的数组的最大子段和，转化为分别求出第1个、第2个、……、第i个、……第n个数字结尾的最大子段和，再找出这n个结果中最大的，即为结果。
//动态规划算法：
//第i个状态（dp[i]）即为以第i个数字结尾的最大子段和（最优解）。由于以第i-1个数字结尾的最大子段和（dp[i-1]）与nums[i]相邻：
//若dp[i-1]>0:
//dp[i] = dp[i-1] + nums[i]
//否则
//dp[i] = nums[i]
//边界值：以第1个数字结尾的最大子段和dp[0] = nums[0]

//解法：
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];

        int max_res = dp[0];

        for(int i = 1; i< nums.size(); i++){
            dp[i] = std::max(nums[i], dp[i-1] + nums[i]);
            if(max_res < dp[i]){
                max_res = dp[i];
            }
        }
        return max_res;

    }
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------
//例4：找零钱
//已知不同面值的钞票，求如何用最少数量的钞票组成某个金额，求可以使用的最少的钞票数量。如果任意数量的已知面值钞票都无法组成该金额，则返回-1。

//思考：
//钞票面值：[1,2,5,10]；金额14；最优解需要3张
//贪心算法：每次使用面值最大的钞票，如：10，2，2可行
//钞票面值：[1，2，5，7，10]；金额14；最优解需要2张（两张7块的）
//贪心算法：10，2，2这就错了，所以贪心并不可选
//结论：
//贪心算法在个别面值组合是可以的，比如日常生活中的RMB面值[1,2,5,10,20,50,100]，但是本题面值不确定，故贪心算法是不可取的

//算法思路：
//钞票面值：coins=[1,2,5,7,10]；金额：14；
//dp[i],代表金额i的最优解（即最小使用张数）
//数组dp[]中存储金额1到金额14的最优解（最少使用钞票的数量）

//在计算dp[i]时，dp[0],dp[1],dp[2].……dp[i-1]都是已知的：
//而金额i可由：
//金额i-1与coins[0](1)组合
//金额i-2与coins[1](2)组合
//金额i-5与coins[2](5)组合
//金额i-7与coins[3](7)组合
//金额i-10与coins[4](10)组合

//即状态i可由状态i-1，i-2，i-5，i-7，i-10，5个状态所转移到，故，
//dp[i] = min(dp[i-1],dp[i-2],dp[i-5],dp[i-7],dp[i-10]) + 1

//设i代表金额，coins[j]代表第j个面值的金额
//当i - coins[j] >= 0 且 dp[i - coins[j]] != -1 时；
//j = 0,1,2,3,4；coins[j] = 1,2,5,7,10
//dp[i] = getmin(dp[i - coins[j]]) + 1


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

//-----------------------------------------------------------------------------------------------------------------------------------------------------
// 例5：三角形
// 给定一个二维数组，其保存了一个数字三角形，求从数字三角形顶端到底端各数字和最小的路径之和，每次可以向下走相邻的两个位置。
// 思考
// 1.从上到下和从下到上的寻找路径的思考方式本质是一样的吗？
// 2.假设dp[i][j]代表三角形的第i行第j列的最优解，从上到下和从下到上的哪种递推方式更容易？（更少的考虑边界条件）

// 算法思路：
// 1、设置一个二维数组，最优值三角形dp[][]，并初始化数组元素为0。dp[i][j]代表了从底向上递推时，走到三角形第i行第j列的最优解
// 2、从三角形底面向三角形上方进行动态规划：
// a、动态规划边界条件：底面上的最优值就是数字三角形的最后一层。
// b、利用i循环，从倒数第二层递推到第一层，对于每层的各列，进行动态规划递推：
// 第i行，第j列的最优解为dp[i][j]，可到达（i,j）的两个位置的最优解为dp[i+1][j]，dp[i+1][j+1]:
// dp[i] = min(dp[i+1][j]，dp[i+1][j+1]) + triangle[i][j];
// 3、返回dp[0][0]

// 解法1：
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        if(triangle.size() == 0){
            return 0;
        }

        std::vector<std::vector<int>> dp;

        for(int i = 0; i < triangle.size(); i++){
            dp.push_back(std::vector<int>());
            for(int j = 0; j < triangle.size(); j++){
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

//-----------------------------------------------------------------------------------------------------------------------------------------------------
// 例6：最长上升子序列
// 已知一个未排序数组，求这个数组最长上升子序列的长度。
// 例如：[1,3,2,3,1,4]
// 其中有很多上升子序列，如[1,3],[1,2,3],[1,2,3,4]等，其中最长的上升子序列长度为4.分别考虑O(n^2)与O(n*logn)两种复杂度算法

// 思考：
// 暴力枚举：[1,3,2,3,1,4]
// n个元素组成的数组，枚举数组的全部子序列，即数组中的任意某个元素都有选择、不选择两种结果，时间复杂度是O(n^2),枚举时选择最长的子序列长度作为结果。

// 若采用动态规划，设第i个状态为dp[i]:
// 1.若第i个状态代表前i个数字中最长上升子序列的长度，是否可以找出dp[i]与dp[i-1]的关系？
// 2.若第i个状态代表以第i个数字为结尾的最长上升子序列的长度，是否可以找出dp[i]与dp[i-1]的关系？再如何求出n个数字的最长上升子序列？
// 3.思考该题与例3-最大子段和的相似之处。

// 分析1：肯定是不行的，推断不出来第i-1和第i之间的关系。
// 分析2：[1,3,2,3,1,4]
// 若第i个状态dp[i]代表以第i个元素结尾的最长上升子序列的长度
// dp[i-1]代表以第i-1个元素结尾的最长上升子序列长度，
// ……
// nums[i]一定是dp[i]所对应的最长上升子序列中最大的元素（因为在末尾）
// 最终结果为dp[0],dp[1],dp[2]……dp[n-1]中的最大值。（与最大子段和相似之处）

// 算法思路
// 设置动态规划数组dp[]，第i个状态dp[i]代表以第i个元素结尾的最长上升子序列的长度：动态规划边界：dp[0] = 1;
// 初始化最长上升子序列的长度LIS = 1；
// 从1到n-1，循环i，计算dp[i]:
// 从0至i-1，循环j，若nums[i] > nums[j]，说明nums[i]可放置在nums[j]的后面，组成最长上升子序列
// 若dp[i] < dp[j] + 1:
// dp[i] = dp[j] + 1;
// LIS为dp[0]，dp[1],……，dp[i],……,dp[n-1]中最大的。

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }//如果数组为空，则返回0

        std::vector<int> dp(nums.size(), 0);//设置存放最长子序列数值的数组dp[]

        dp[0] = 1;//初始化边界条件

        int LIS = 1;//初始化最长上升子序列的长度LIS = 1

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


//-----------------------------------------------------------------------------------------------------------------------------------------------------
// 设置一个栈(使用vector实现)stack，stack[i]代表长度为i+1的上升子序列最后一个元素的最小可能取值，即若要组成长度为i+2的上
// 升子序列，需要一个大于stack[i]的元素。最终栈的大小，即为最长上升子序列长度。

// nums = [1, 3,2,3,1,4]
// 1.设置一个栈(使用vector实现)，将nums[0] push栈中。
// 2.从1至n-1遍历nums数组:
//                  若nums[i]>栈顶:将nums[i] push至栈中。
//                 否则:
//                  从栈底遍历至栈顶，若遍历时，栈中元素大于等于nums[i],
//                  使用nums[i]替换该元素，并跳出循环。
// 3.返回栈的大小。

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }//如果数组为空，则返回0

        std::vector<int> stack;//设置一个vector
        stack.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > stack.back()){
                stack.push_back(nums[i]);
            }
            else{
                for(int j = 0; j < stack.size(); j++){
                    if(stack[j] >= nums[i]){    //这里别忘记了vector元素的访问方法，这里的stack是类似于栈的vector，并不是stack，所以别一直想着 .pop(), .push_back(),这样的
                        stack[j] = nums[i];
                        break;
                    }
                }
            }
        }
        return stack.size();
    }
};

// 上面的解法优化：
int binary_search(std::vector<int> nums, int target){
    int index = -1;
    int begin = 0;
    int end = nums.size() - 1;
    while(index == -1){
        int mid = (begin + end) / 2;
        if(target == nums[mid]){
            index = mid;
        }
        else if(target < nums[mid]){
            if(mid == 0 || target > nums[mid - 1]){
                index = mid;
            }
            end = mid - 1;
        }
        else if(target > nums[mid]){
            if(mid == nums.size() - 1 || target < nums[mid + 1]){
                index = mid + 1;
            }
            begin = mid + 1;
        }
    }
    return index;
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }//如果数组为空，则返回0

        std::vector<int> stack;//设置一个vector
        stack.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > stack.back()){
                stack.push_back(nums[i]);
            }
            else{
                int pos = binary_search(stack, nums[i]);
                stack[pos] = nums[i];
            }
        }
        return stack.size();
    }
};














