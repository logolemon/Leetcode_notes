//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
//书上的解法：
//利用指针进行交换操作，具体就是看好指针的走向，可以利用画图的方法来具体的看看怎么走的
//迭代解法：
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = head, *s;
        if(p && p->next){
            s = p->next;
            p->next = s->next;
            s->next = p;
            head = s;
            while(p->next && p->next->next){
                s = p->next->next;
                p->next->next = s->next;
                s->next = p->next;
                p->next = s;
                p = s->next;
            }
        }
        return head;
           
    }
};//执行用时：4ms 内存消耗：7.3MB

//递归解法：
