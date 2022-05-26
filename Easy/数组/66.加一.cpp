// 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
// 你可以假设除了整数 0 之外，这个整数不会以零开头。

// 解法1：
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for(int i = digits.size() - 1; i >= 0; i--){
            digits[i]++;
            if(digits[i] % 10 != 0){
                for(int j = i + 1; j < digits.size(); j++){//这两行代码针对的就是[1,3,9]这样的例子，最后面都要变成0
                    digits[j] = 0;
                }
                return digits;
            }
        }

        std::vector<int> new_digits(digits.size() + 1, 0);//切记初始化数组的方法
        new_digits[0] = 1;
        return new_digits;

    }
};
