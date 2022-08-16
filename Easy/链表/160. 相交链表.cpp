//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。

//解法1：时间复杂度（O（nlogn）），空间复杂度O（n）
//使用STL::set求交集
//1.遍历链表A，将A中节点对应的指针（地址），插入set
//2.遍历链表B，将B中节点对应的指针（地址），在set中查找，发现在set中的第一个节点地址，即是两个链表的交点 

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::set<ListNode*> node_set;//设置查找集合node_set
        while(headA){
            node_set.insert(headA);//将链表A中的节点插入node_set
            headA = headA->next;
        }
        while(headB){
            if(node_set.find(headB) != node_set.end()){
                return headB;//当在headB中找到第一个出现在node_set中的节点时
            }
            headB = headB->next;
        }
        return NULL;
    }
};
//执行用时：72ms 内存消耗：17.6MB

//解法2：时间复杂度O(n)，空间复杂度O(1)
//1.计算链表A和链表B的长度，较长的链表多出的长度
//2.将较长的链表的指针移动到和较短的链表指针对齐的位置
//3.headA和headB同时移动，当两个指针指向同一节点时，就是找到了

int get_list_length(ListNode *head){//遍历链表，计算链表的长度
    int len = 0;
    while(head)
    {
        len++;
        head = head->next;
    }
    return len;
}

ListNode *forward_long_list(int long_len, int short_len, ListNode *head){//将指针向前移动至多出节点个数后面的位置
    int delta = long_len - short_len;
    while(head && delta){
        head = head->next;
        delta--;
    }
    return head;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int list_A_len = get_list_length(headA);
        int list_B_len = get_list_length(headB);

        if(list_A_len > list_B_len){
            headA = forward_long_list(list_A_len, list_B_len, headA);
        }
        else{
            headB = forward_long_list(list_B_len, list_A_len, headB);
        }
        while(headA && headB){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
//执行用时：48 ms 内存消耗：14.2 MB

//解法3：双指针 数学思维
//情况1：两个链表相交
//链表headA和headB的长度分别是m和n。假设链表headA的不相交部分有α个节点，链表headB的不相交部分有b个节点，两个链表相交的部分有c个节点，则有a+c=m， b＋c=n
//如果a=b，则两个指针会同时到达两个链表相交的节点，此时返回相交的节点；
//如果a ≠ b，指针pA会遍历完headA，指针pB会遍历完headB，但是他们不会同时到达链表的尾节点，然后pA移动到链表headB的头节点，指针pB移动到headA的头节点。然后两个指针继续移动，
//在指针pA移动了 a + c + b次，指针pB移动了 b + c + a次以后，两个指针会同时到达链表相交的节点，该节点也是两个指针第一次同时指向的节点，此时返回相交的节点

//情况1：两个链表不相交
//链表headA和链表headB的长度分别是m和n。考虑当m = n 和 m ≠ n时，两个指针分别会如何移动
//如果m=n，则两个指针会同时到达两个链表的尾节点，然后同时变成空值null，此时返回null ;
//如果m ≠ n，则由于两个链表没有公共节点，两个指针也不会同时到达两个链表的尾节点，因此两个指针都会遍历完两个链表，在指针pA移动了m+n次、指针pB移动了n+m次之后，
//两个指针会同时变成空值null，此时返回null。

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }

        ListNode *pA = headA, *pB =headB;
        while(pA != pB){
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }

        return pA;
    }
};
//执行用时：44 ms 内存消耗：14.2 MB

