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

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 解法2：
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

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 解法2优化(n*logn)：
// 二分查找nums[i]的位置
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
