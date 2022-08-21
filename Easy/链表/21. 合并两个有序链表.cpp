//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

//思路：比较l1和l2指向的节点，将较小的节点插入到pre指针后，并向前移动较小节点对应的指针

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode temp_head(0);//创建一个头节点
        ListNode *pre = &temp_head;//用一个指针指向创建好的头节点
        while(list1 && list2){
            if(list1->val < list2->val){//list1 和 list2 同时不空时，对他们进行比较
                pre->next = list1;
                list1 = list1->next;
            }
            else{
                pre->next = list2;
                list2 = list2->next; 
            }
            pre = pre->next;
        }

        if(list1){
            pre->next = list1;
        }
        if(list2){
            pre->next = list2;
        }
        return temp_head.next;
        
    }
};
