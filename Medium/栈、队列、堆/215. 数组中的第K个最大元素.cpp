// 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
// 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

// 维护一个K大小的最小堆，堆中元素个数小于K时，新元素直接入堆，否则，当堆顶的元素小于新元素时，弹出堆顶，将新元素加入堆
// 解释：
// 由于堆是最小堆，堆顶是堆中最小元素，新元素都会保证比堆顶小（否则新元素替换堆顶），故堆中第K个元素是已扫描的元素里最大的K个;堆顶即为第K大的数。

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {//最小堆
        std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
        for(int i = 0; i < nums.size(); i++){//遍历nums数组
            if(Q.size() < k){
                Q.push(nums[i]);//如果堆中元素个数小于k，直接push进入堆
            }
            else if(Q.top() < nums[i]){//如果堆顶的元素比新元素小，弹出堆顶，push进新元素（替换堆顶）
                Q.pop();
                Q.push(nums[i]);
            }
        }
        return Q.top();
    }
};
// 执行用时：80ms  内存消耗：46.1MB
