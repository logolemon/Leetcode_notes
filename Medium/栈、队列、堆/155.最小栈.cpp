//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//实现 MinStack 类:
//MinStack() 初始化堆栈对象。
//void push(int val) 将元素val推入堆栈。
//void pop() 删除堆栈顶部的元素。
//int top() 获取堆栈顶部的元素。
//int getMin() 获取堆栈中的最小元素。

//分析:用另一个栈，存储各个状态下的最小值.
class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        _data.push(val);//将数据压入数据栈
        if(_min.empty()){
            _min.push(val);
        }
        else {//如果新数据大于最小值的栈顶
            if(val > _min.top()){
            val = _min.top();//更新val的值
            }
            _min.push(val);
        }
    }
    
    void pop() {
        _data.pop();
        _min.pop();
    }
    
    int top() {
        return _data.top();
    }
    
    int getMin() {
        return _min.top();
    }

private:
    std::stack<int> _data;//数据栈
    std::stack<int> _min;//最小值栈
};//执行用时:24ms 内存消耗:15.9MB
