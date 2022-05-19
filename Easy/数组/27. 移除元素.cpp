//我自己的方法还是采用快慢(指针)的方式，用nums[fast]去和指定的val元素进行对比，不相等则slow和fast一起前进，如果碰到了val元素，则slow原地呆着不动，fast前进。
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
        return 0;
        int slow = 0;
        for(int fast = 0; fast != nums.size(); fast++)
        {
            if(nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
        
    }
};
