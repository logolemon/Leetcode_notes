
//给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
//由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。更规范地说，如果在删除重复项之后有 k 个元素，那么 nums /的前 k 个元素应该保存最终结果。
//将最终结果插入 nums 的前 k 个位置后返回 k 。
//不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成

//输入：nums = [1,1,2]
//输出：2, nums = [1,2,_]
//解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         if (nums.size() == 0)
            return 0;//如果数组的长度为0 得考虑一下，输出0，考虑它的边界条件
        int slow = 1;//设置一个慢指针，fast是一个快指针
        for (int fast = 1; fast < nums.size(); fast++){//遍历数组，如果快指针指向的数组元素和上一个数组元素不相同，那么就是slow和fast都往前进一步
            if (nums[fast] != nums[fast - 1])
            {
                nums[slow] = nums[fast];
                ++slow;
            }
        }
        return slow;
    }
};
