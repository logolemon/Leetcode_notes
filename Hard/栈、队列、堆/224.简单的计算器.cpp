//设计一个计算器，输入一个字符串存储的数学表达式，可以计算包括“("、”)"'、”+”、”-”四种符号的数学表达式，
//输入的数学表达式字符串保证是合法的。输入的数学表达式中可能存在空格字符。

//字符串转换成数字的实现
int main(){
  int number = 0;
  std::string s = "12345";
  for(int i = 0; i < s.length(); i++){
    number = number * 10 + s[i] - '0';
  }
  return 0;
}

//计算函数
void compute(std::stack<int> &number_stack, std::stack<char> &operation_stack){
  if(number_stack.size() < 2){
        return;
    }
    int num2 = number_stack.top();
    number_stack.pop();
    int num1 = number_stack.top();
    number_stack.pop();
    if(operation_stack.top() == '+'){
        number_stack.push(num1 + num2);
    }
    else if(operation_stack.top() == '-'){
        number_stack.push(num1 - num2);
    }
    operation_stack.pop();
}

//字符串处理思路，有限状态机处理机制
// 1).如果是数字字符 number = number * 10 + ch - '0'
// 2).否则：number进入数字栈， number_stack.push 根据compute_flag进行计算，并切换至OPERATION_STATE，并将字符指针退格，number = 0！

// 1).如果+ - ; operation_stack.push compute_flag = 1
// 2).如果( ; compute_flag = 0 切换至NUMBER_STATE
// 3).如果) ; 进行计算compute
// 4).如果0-9 ; 切换至NUMBER_STATE，注意字符指针i退格

void compute(std::stack<int> &number_stack, std::stack<char> &operation_stack){
    if(number_stack.size() < 2){
        return ;
    }
    int num2 = number_stack.top();
    number_stack.pop();
    int num1 = number_stack.top();
    number_stack.pop();
    if(operation_stack.top() == '+'){
        number_stack.push(num1 + num2);
    }
    else if(operation_stack.top() == '-'){
        number_stack.push(num1 - num2);
    }
    operation_stack.pop();
}

class Solution {
public:
    int calculate(string s) {
        static const int STATE_BEGIN = 0;
        static const int NUMBER_STATE = 1;
        static const int OPERATION_STATE = 2;
        std::stack<int> number_stack;
        std::stack<char> operation_stack;
        int number = 0;
        int STATE = STATE_BEGIN;
        int compute_flag = 0;
        number_stack.push(0);
        operation_stack.push('+');
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                continue;
            }
            switch(STATE){
                case STATE_BEGIN:
                    if(s[i] >= '0' && s[i] <= '9'){
                        STATE = NUMBER_STATE;
                    }
                    else{
                        STATE = OPERATION_STATE;
                    }
                    i--;
                    break;
                
                case NUMBER_STATE:
                    if(s[i] >= '0' && s[i] <= '9'){
                        number = number * 10 + s[i] - '0';
                    }
                    else{
                        number_stack.push(number);
                        if(compute_flag == 1){
                            compute(number_stack, operation_stack);
                        }
                        number = 0;
                        i--; 
                        STATE = OPERATION_STATE;
                    }
                    break;

                case OPERATION_STATE:
                    if(s[i] == '+' || s[i] == '-'){
                        operation_stack.push(s[i]);
                        compute_flag = 1;
                    }
                    else if(s[i] == '('){
                        STATE = NUMBER_STATE;
                        compute_flag = 0;
                    }
                    else if(s[i] >= '0' && s[i] <= '9'){
                        STATE = NUMBER_STATE;
                        i--;
                    }
                    else if(s[i] == ')'){
                        compute(number_stack, operation_stack);
                    }
                    break;
            }
        }
        if(number != 0){
            number_stack.push(number);
            compute(number_stack, operation_stack);
        }
        if(number == 0 && number_stack.empty()){
            return 0;
        }
        return number_stack.top();
    }
};//执行用时：16ms 内存消耗：8.9MB

