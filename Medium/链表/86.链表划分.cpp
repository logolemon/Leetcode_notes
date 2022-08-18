//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有小于x的节点都出现在大于或等于x的节点之前。你应当保留两个分区中每个节点的初始相对位置。

//思路：巧用临时头节点

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode less_head(0);
        ListNode more_head(0);//设置两个临时头节点
        ListNode* less_ptr = &less_head;
        ListNode* more_ptr = &more_head;//对应指针指向这两个临时头节点

        while(head){
            if(head->val < x){//如果节点的值小于x，则将该节点插入到less_ptr之后
                less_ptr->next = head;
                less_ptr = less_ptr->next;//链接完成后，less_ptr向后移动，指向head
            }
            else{//否则将该节点插入到more_ptr之后
                more_ptr->next = head;
                more_ptr = more_ptr->next;
            }
            head = head->next;//遍历链表
        }

        less_ptr->next = more_head.next;
        more_ptr->next = nullptr;//将more_ptr即链表尾节点next清空

        return less_head.next;//less_head的next节点即为新链表的头节点，返回

    }
};
//执行用时：8 ms 内存消耗：10 MB
