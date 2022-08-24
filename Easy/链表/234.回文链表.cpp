//给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

//解法1：先使用快慢指针找到链表中点，再把链表切成两半，然后把后半段翻转，最后比较两半是否相等。
//反转链表的辅助函数
ListNode *reverseList(ListNode *head){
    ListNode *prev = nullptr, *next;
    while(head){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
//主函数
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //找到链表的中点
        if(head == nullptr || head->next == nullptr){
            return true;
        }
        ListNode *slow = head, *fast = head;//定义快慢指针，用来找链表的中点
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);//将slow的下一个节点指向已经反转好的链表的头节点
        slow = slow->next;//现在slow就已经指向了已经反转好的链表的头节点了
        //接下来就是进行比较
        while(slow){
            if(head-> val != slow->val){
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};//执行用时：180ms 内存消耗：115.3MB
