//题目描述
//给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。构造这个链表的深拷贝。
//深拷贝应该正好由 n 个全新节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，
//并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。
//例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 

//必备知识：STL map的使用
//STL Map是关联式容器，它提供一对一的处理能力（其中第一个可以称为关键字，每个关键字只能在map中出现一次，第二个可能称为该关键字的值），在我们处理一对一数据的时候，在编程上提供
//快速通道，map内部数据的组织，map内部自建一棵红黑树（一种非严格意义上的平衡二叉树），这棵树具有对数据自动排序的功能。

//1.map简介
//map是一类关联式容器。它的特点是增加和删除节点对迭代器的影响很小，除了那个操作节点，对其他的节点都没有什么影响。对于迭代器来说，可以修改实值，而不能修改key。

//2.map的功能
//自动建立 Key － value 的对应。key 和 value可以是任意你需要的类型。

//3.数据的插入
//第一种：用insert函数插入pair数据
//mapStudent.insert(pair<int, string>(1, "student_one"));
//第二种：用insert函数插入value_type数据
//第三种：用数组方式插入数据

//4.map的大小
//Int nSize = mapStudent.size();

class Solution {
public:
    Node* copyRandomList(Node* head) {//返回的是深度拷贝后的链表，深度拷贝：构造生成一个完全新的链表，即使原链表破坏，新链表可独立使用
    std::map<Node *, int> node_map;//地址到节点位置的map
    std::vector<Node *> node_vec;//使用vector根据存储节点位置访问地址
    Node *ptr = head;
    int i = 0;
    while(ptr){//将新链表节点push入node_vec,生成了新链表节点位置到地址的map 
        node_vec.push_back(new Node(ptr->val));
        node_map[ptr] = i;//记录原始链表地址至节点位置的node_map
        ptr = ptr->next;//遍历原始链表
        i++;//记录节点的位置
    }
    node_vec.push_back(0);
    ptr = head;
    i = 0;
    while(ptr){//再次遍历原始链表，链接新链表的next指针、random指针
        node_vec[i]->next = node_vec[i+1];//链接新链表next指针
        if(ptr->random){//当random指针不空时
            int id = node_map[ptr->random];//根据node_map确认原链表random指针指向的位置 即id
            node_vec[i]->random = node_vec[id];//连接新链表random指针
        }
        ptr = ptr->next;
        i++;
    }
        return node_vec[0];
    }
};
//执行用时：4 ms  内存消耗：11 MB
