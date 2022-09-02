//已知从1-n的数字序列，按顺序入栈，每个数字入栈后即可出栈，也可以在栈中停留，等待后面的数字入栈出栈后，该数字再出栈，求该数字序列的出栈序列是否合法？

//思路：运用栈和队列模拟入栈，出栈过程
//1.出栈结果存储在队列queue中
//2.按顺序，将元素push进入栈
//3.每push一个元素，即检查是否与队列首部元素相同若相同则弹出队列元素，弹出栈顶元素，直到两元素不同结束
//4.若最终栈为空，说明序列合法，否则不合法

bool check_is_valid_order(std::queue<int> &order){//检查队列（存储在队列中）
    std::stack<int> S;//S是模拟栈
    int n = order.size();//n为序列的长度，将1-n顺序入栈
    for(int i = 1; i <= n; i++){
        S.push(i);
        while(!S.empty() && order.front() == S.top()){
            S.pop();
            order.pop();
        }
    }
    if(!S.empty()){//如果栈不为空，就返回false即不是合法的序列
        return false;
    }
    return true;
}//整体的算法复杂度是O（n）
