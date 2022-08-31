//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表。
//进阶：你可以在 O(nlogn)时间复杂度和常数级空间复杂度下，对链表进行排序吗？
//分析：插入排序的时间复杂度是O（n^2）,其中n是链表的长度。题目的进阶问题要求达到 O(nlogn)的时间复杂度和O(1)的空间复杂度，时间复杂度是 O(nlogn)的排序算法包括
//归并排序、堆排序和快速排序（快速排序的最差时间复杂度是 O(n^2)，其中最适合链表的排序算法是归并排序。

//方法一：自顶向下归并排序
//1.找到链表的中点，以中点为分界，将链表拆分成两个子链表。寻找链表的中点可以使用快慢指针的做法，快指针每次移动 22 步，慢指针每次移动 11 步，当快指针到达链表末尾时，慢指针指向的链表节点即为链表的中点。
//2.对两个子链表分别排序。
//3.将两个排序后的子链表合并，得到完整的排序后的链表。可以使用「21. 合并两个有序链表」的做法，将两个有序的子链表进行合并。

//上述过程可以通过递归实现。递归的终止条件是链表的节点个数小于或等于1，即当链表为空或者链表只包含1个节点时，不需要对链表进行拆分和排序。
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }
    ListNode *sortList(ListNode *head, ListNode *tail){//快慢指针去找到链表的中点，是递归的方法
        if(head == nullptr){
            return head;
        }
        if(head->next == tail){
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head, *fast = head;
        while(fast != tail){
            slow = slow->next;
            fast = fast->next;
            if(fast != tail){
                fast = fast->next;
            }
        }
        ListNode *mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode *merge(ListNode *head1, ListNode *head2){//非递归的算法，将两个链表进行合并，采用临时的节点dummyHead作为新链表的头节点
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};//执行用时：224ms 内存消耗：72.2MB
