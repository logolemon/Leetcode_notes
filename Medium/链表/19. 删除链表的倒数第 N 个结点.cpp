//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

//方法一：计算链表的长度
//因为当链表的形式是［1，2］n = 2的时候，就需要输出［2］，但是经常返回的是链表的头节点，所以构造一个虚拟的“伪节点”dummy。那么对头节点的操作就和普通的节点没区别了
class Solution {
public:
    int getlength(ListNode *head){//计算链表的长度
        int deta = 0;
        while(head){
            ++deta;
            head = head->next;
        }
        return deta;
    };

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);//构造虚拟的头节点
        int length = getlength(head);//获取长度
        ListNode *slow = dummy;
        int movenum = length - n;
        while(slow != nullptr && movenum--){
            slow = slow->next;
        }
        ListNode *next = slow;
        if(slow != nullptr && slow->next != nullptr){
            next = slow->next;
        }
        if(next !=nullptr){        
            slow->next = next->next;
        }

        return dummy->next;//返回的是虚拟头节点的下一个节点
    }
};//执行用时：4ms 内存消耗：10.3 MB

//方法二：栈方法
//我们也可以在遍历链表的同时将所有节点依次入栈。根据栈「先进后出」的原则，我们弹出栈的第n个节点就是需要删除的节点，
//并且目前栈顶的节点就是待删除节点的前驱节点。这样一来，删除操作就变得十分方便了。
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        stack<ListNode*> stk;
        ListNode *cur = dummy;
        while(cur){
            stk.push(cur);
            cur = cur->next;
        }
        for(int i = 0; i < n; i++){
            stk.pop();
        }
        ListNode *pre = stk.top();
        pre->next = pre->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
        
    }
};//执行用时：4ms 内存消耗：10.5 MB

//方法三：双指针,就是让快指针先走n个节点，然后和慢指针一起走，当快指针走到链表尾的时候，慢指针刚好走到要被删除节点的前一个节点，然后删除就好了
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *second = dummy;
        ListNode *first = head;
        
        for(int i = 0; i < n; i++){
            first = first->next;
        }
        while(first){
            second = second->next;
            first = first->next;
        }

        second->next = second->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
        
    }
};
