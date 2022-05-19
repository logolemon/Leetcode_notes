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
//lower_bound()函数用于在指定的区域内查找不小于目标值的第一个元素，简单的说，就是查找的比目标值大的第一个元素
//lower_bound() 函数定义在<algorithm>头文件中，其语法格式有 2 种，分别为：
//在 [first, last) 区域内查找不小于 val 的元素
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,
                             const T& val);
//在 [first, last) 区域内查找第一个不符合 comp 规则的元素
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,
                             const T& val, Compare comp);
//first，last分别是容器的起始迭代器，这个函数最后返回的也是一个迭代器，val是目标函数，就是这个题的target，然后最后一个参数comp是自定义规则，就是可以自己制定它的规则。

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      
        return lower_bound(nums.begin(),nums.end(),target) - nums.begin();  
    }
};
