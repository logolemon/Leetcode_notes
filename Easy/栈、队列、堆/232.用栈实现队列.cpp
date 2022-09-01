//双栈操作，和235题思路是一样的
class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        std::stack<int> temp_stack;
        while(!data_stack.empty()){
            temp_stack.push(data_stack.top());
            data_stack.pop();
        }
        temp_stack.push(x);
        while(!temp_stack.empty()){
            data_stack.push(temp_stack.top());
            temp_stack.pop();
        }
    }
    
    int pop() {
        int x = data_stack.top();
        data_stack.pop();
        return x;
    }
    
    int peek() {
        return data_stack.top();
    }
    
    bool empty() {
        return data_stack.empty();
    }

private:
    std::stack<int> data_stack;
};//执行用时：0ms 内存消耗：6.7MB
