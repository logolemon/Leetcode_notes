

// 解法1：自己写出来解法，遇到0，则去找它下一个不为零的元素，然后进行替换。
// 执行用时:236 ms ,在所有C++提交中击败了6.17%的用户
// 内存消耗:18.7 MB ，在所有C++提交中击败了64.00%的用户
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                for(int j = i; j < n; j++){
                    if(nums[j] != 0){
                        nums[i] = nums[j];
                        nums[j] = 0;
                        break;
                    }
                }
            }
        }
    }
};
