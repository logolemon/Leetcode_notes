// 中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
// 例如，
// [2,3,4] 的中位数是 3
// [2,3] 的中位数是 (2 + 3) / 2 = 2.5
// 设计一个支持以下两种操作的数据结构：
// void addNum(int num) - 从数据流中添加一个整数到数据结构中。
// double findMedian() - 返回目前所有元素的中位数。

// 最直观的方法：
// 存储结构使用数组，每次添加元素或查找中位数时对数组排序，现计算结果。
// 时间复杂度：
// 1.若添加元素时排序，addNum复杂度O（n），findMedian复杂度O（1）
// 2.若查找中位数时排序，addNum复杂度O（1），findMedian复杂度O（nlogn）
// 若添加元素或查询中位数是随机的操作，共n次操作，按上述思想，整体复杂度最佳为O（n^2）

// 动态维护一个最大堆和一个最小堆，最大堆存储一半数据，最小堆存储一半数据，维持最大堆的堆顶比最小堆的堆顶小

class MedianFinder {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> small_queue;//最小堆
    std::priority_queue<int, std::vector<int>, std::less<int>> big_queue;//最大堆

    MedianFinder() {}
    
    void addNum(int num) {
        if(big_queue.empty()){
            big_queue.push(num);
            return;
        }
        if(big_queue.size() == small_queue.size()){
            if(num < big_queue.top()){
                big_queue.push(num);
            }
            else {
                small_queue.push(num);
            }
        }
        else if(big_queue.size() > small_queue.size()){
            if(num  > big_queue.top()){
                small_queue.push(num);
            }
            else {
                small_queue.push(big_queue.top());
                big_queue.pop();
                big_queue.push(num);
            }
        }
        else if(big_queue.size() < small_queue.size()){
            if(num < small_queue.top()){
                big_queue.push(num);
            }
            else {
                big_queue.push(small_queue.top());
                small_queue.pop();
                small_queue.push(num);
            }
        }

    }
    
    double findMedian() {
        if(big_queue.size() == small_queue.size()){
            return (big_queue.top() + small_queue.top()) / 2.0;
        }
        else if(big_queue.size() > small_queue.size()){
            return big_queue.top();
        }
        else {
            return small_queue.top();
        }
    }
};
