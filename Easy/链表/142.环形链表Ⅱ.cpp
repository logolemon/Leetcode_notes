//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

//解法1：
//1.遍历链表，将链表中的节点对应的指针（地址）插入set
//2.在遍历时插入节点前，需要在set中查找，第一个在set中发现的节点地址，即是链表环的起始节点

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        std::set<ListNode *> node_set;
        while(head){//遍历链表
            if(node_set.find(head) != node_set.end()){//如果在node_set已经出现了
                return head;//返回环的第一个节点
            }
            node_set.insert(head);//将节点插入node_set
            head = head->next; 
        }
        return NULL;//没有遇到环则返回Null
    }
};
//时间复杂度：O(N)，空间复杂度：O(N)
//执行用时：16ms 内存消耗：9.7 MB

//解法2：快慢指针赛跑
//数学思维，f = 2s, f = s + nb，慢指针走了 s = nb，b是环的周长，n是跑的圈数，那么需要走到环的入口的话就是 k = a + nb 所以还需要走a步，所以我们可以来一个头指针走a步就可以
//走到环的入口节点处了，刚好慢指针再走a步停下来也就是环的入口了！
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;//快指针
        ListNode *slow = head;//慢指针
        ListNode *meet = NULL;//相遇的节点指针
        while(fast){
            slow = slow->next;
            fast = fast->next;
            if(!fast){//如果fast为空
                return NULL;
            }
            fast = fast->next;//fast再走一步
            if(fast == slow){
                meet = fast;//fast和slow相遇，记录相遇的位置
                break;      
            }        
        }
        if(meet == NULL){
            return NULL;//如果没有相遇，说明链表没有环
        }
        while(head && meet){
            if(head == meet){//当head和meet相遇，说明遇到环的起始位置
                return head;
            }
            head = head->next;
            meet = meet->next;
        }
        return NULL;

    }
};

//时间复杂度：O(N)，空间复杂度：O(1)
//执行用时：12ms 内存消耗：7.5 MB
