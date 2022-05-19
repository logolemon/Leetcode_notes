//第一种：二分查找的解法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int left = 0;//数组左边的索引
        int right = nums.size() - 1;//数组右边的索引

        //目标值不存在，且target最小
        if(target < nums[left])
        return 0;
        //目标值不存在，且target最大
        if(target > nums[right])
        return right + 1;

        //二分查找目标值
        while(left <= right)
        {
            int mid = left + (right - left) /2;//定义一个中间的临时变量，防止数值溢出
            if(target > nums[mid])//target在数组的右侧
                left = mid + 1;
            else if(target < nums[mid])//target在数组的左侧
                right = mid - 1;
            else
                return mid;
        }
        return left;//记住一定得有这个返回值
    }
};

//第二种：采用STL容器的解法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      
        return lower_bound(nums.begin(),nums.end(),target) - nums.begin();  
    }
};
