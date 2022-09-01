class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        std::queue<int> temp_queue;//临时队列，利用该队列进行原始data_queue元素与新元素的次序进行调换
        temp_queue.push(x);//对于新元素x的操作
        while(!_data.empty()){
            temp_queue.push(_data.front());
            _data.pop();
        }
        while(!temp_queue.empty()){
            _data.push(temp_queue.front());
            temp_queue.pop();
        }
    }
    
    int pop() {//pop弹出栈顶并返回栈顶元素
        int x = _data.front();//取栈顶元素，即为队列头部元素
        _data.pop();//弹出队列头部元素
        return x;//返回取出的队列头部元素x，即为栈顶元素
    }
    
    int top() {
        return _data.front();//返回栈顶即直接返回队列头部元素
    }
    
    bool empty() {
        return _data.empty();
    }

private:
    std::queue<int> _data;//_data数据队列存储元素的顺序，就是栈存储元素的顺序
};//执行用时：0ms 内存消耗：6.7MB
