//给你一个链表数组，每个链表都已经按升序排列。请你将所有链表合并到一个升序链表中，返回合并后的链表。
//以知k个已排序链表的头节点指针，将这k个链表合并，合并后仍为有序的，返回合并后的头节点。

//方案1：最普通的办法，k个链表按顺序合并k-1次
//设有k个链表，平均每个链表有n个节点，时间复杂度：（n+n）+（2n+n）+（（k-1）n+n）= O（k^2*n）
//时间复杂度太高了

//方案2：将k*n个节点放到vector中，再将vector排序，再将节点顺序相连。
//设有k个链表，平均每个链表有n个节点，时间复杂度：kN*logkN + kN = O（kN*logkN）
bool cmp(const ListNode *a, const ListNode *b){
    return a->val < b->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::vector<ListNode *> node_vec;
        for(int i = 0; i < lists.size(); i++){
            ListNode *head =lists[i];//遍历k个链表，将节点全部添加至node_vec
            while(head){
                node_vec.push_back(head);//vector添加是push_back()方法;
                head = head->next;
            }
        }
        if(node_vec.size() == 0){
            return NULL;
        }
        std::sort(node_vec.begin(), node_vec.end(), cmp);
            for(int i = 1; i < node_vec.size(); i++){
                node_vec[i-1]->next = node_vec[i];//连接新的链表，上面的循环定义的是 i=1；
            }
        node_vec[node_vec.size() - 1]->next = NULL;
        return node_vec[0];
        
    }
};
//执行用时：24ms 内存消耗：13.2MB


//方案3：对k个链表进行分制，两两进行合并。
//设有k个链表，平均每个链表有n个节点，时间复杂度：
//第1轮，进行k/2次，每次处理2n个数字；第2轮，进行k/4次，每次处理4n个数字；
//最后一次：进行k/（2^logk）次，每次处理2^logk*N个值，O（kNlogk）

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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){//如果lists为空，返回NULL
            return NULL;
        }
        if(lists.size() == 1){//如果只有一个list，直接返回头指针
            return lists[0];
        }
        if(lists.size() == 2){//如果只有两个list，调用两个list merge函数
            return mergeTwoLists(lists[0], lists[1]);
        }

        int mid = lists.size()/2;

        std::vector<ListNode*> sub1_lists;//拆分lists为两个子lists
        std::vector<ListNode*> sub2_lists;
        for(int i = 0; i < mid; i++){
            sub1_lists.push_back(lists[i]);
        }
        for(int i = mid; i < lists.size(); i++){
            sub2_lists.push_back(lists[i]);
        }

        ListNode *l1 = mergeKLists(sub1_lists);
        ListNode *l2 = mergeKLists(sub2_lists);
        
        return mergeTwoLists(l1, l2);//分制处理
    }
};
//执行用时：24ms 内存消耗：29.9MB
