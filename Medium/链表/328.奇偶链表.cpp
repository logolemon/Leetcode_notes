//给定单链表的头节点 head ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。
//请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。

//定义三个指针，分离链表的操作来解决这个题目。

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }

        ListNode *odd = head;
        ListNode *evenhead = head->next;
        ListNode *even = evenhead;
        while(even != nullptr && even->next!=nullptr){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            odd->next = evenhead;
            even = even->next;
        }
        return head;
    }
};//执行用时：4ms 内存消耗：10.3MB，odd->next = evenhead 放在循环里面比较好。

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }

        ListNode *odd = head;
        ListNode *evenhead = head->next;
        ListNode *even = evenhead;
        while(even != nullptr && even->next!=nullptr){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};//执行用时：12ms 内存消耗：10.3MB
