//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

//非递归的写法为,迭代的解法：
//书上的解答过程
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *next;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};//执行用时：8ms 内存消耗：8Mb

//迭代解法：
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;//定义一个指针
        ListNode *curr = head;//定义一个指针来指向链表的头节点
        while(curr){//当节点不为空的时候
            ListNode *next = curr->next;//定义一个临时节点来保存指针的下一个节点
            curr->next = prev;//这两步就是在反转链表
            prev = curr;//后移
            curr = next;//后移
        }
        return prev;
    }
};//执行用时：4ms 内存消耗：8Mb

//小象学院的解答：
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head = nullptr;//指向新链表头节点的指针
        while(head)
        {
            ListNode *next = nullptr;
            next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        return new_head;

    }
};//执行用时：8ms 内存消耗：8Mb

//递归的写法为：
//书上的解答过程
class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* prev = nullptr) {
        if(!head){
            return prev;
        }
        ListNode *next = head->next;
        head->next = prev;
        return reverseList(next, head);
    }
};//执行用时：8ms 内存消耗：7.9Mb

//leedcode评论区的解法
//递归解法
//为什么可以使用递归？
//1、大问题拆成两个子问题：一个是头节点，另一个是除了头节点以外的后面的节点组成的节点 
//2、子问题的求解方式和大问题一样
//3、存在最小子问题
//递归解法思路
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next==nullptr) return head;
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};//执行用时：4ms 内存消耗：8.2Mb
