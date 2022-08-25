//给定一个已排序的链表的头 head，删除所有重复的元素，使每个元素只出现一次。返回已排序的链表。
//自己写的方法
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head, *r;//定义三个工作指针p，q，r，然后p遍历全表，p每到一个节点，q就从这个节点往后遍历，并与p的数值比较，相同的话就free掉那个节点
        if(!p || !p->next){
            return head;
        }

        while(p && p->next){//这个地方的链表循环条件注意一下
            ListNode *q = p;
            while(q->next){
                if(p->val == q->next->val){
                    r = q->next;
                    q->next = r->next;
                }
                else{
                    q = q->next;
                }
            }     
            p = p->next;
        }
        return head;
    }
};//执行用时：16ms 内存消耗：11.3MB

//采用set容器的方法
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> s;
        ListNode *cur = head;
        while(cur && cur->next){
            s.insert(cur->val);
            //如果此节点重复，则跨过cur->next
            if(s.count(cur->next->val)) cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return head;
    }
};//执行用时：12ms 内存消耗：12MB
