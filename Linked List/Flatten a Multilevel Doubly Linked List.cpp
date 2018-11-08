/*430. 扁平化多级双向链表
您将获得一个双向链表，除了下一个和前一个指针之外，它还有一个子指针，可能指向单独的双向链表。这些子列表可能有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。
扁平化列表，使所有结点出现在单级双链表中。您将获得列表第一级的头部。

示例:

输入:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

输出:
1-2-3-7-8-11-12-9-10-4-5-6-NULL
*/


/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/

/*刚开始的想法是分为两个过程
第一个过程是找到带有子链的结点后 将该结点的next和child对换 然后继续遍历知道找到一个next和child均为空的结点
这时形成了扁平化的前一部分 剩余的子链部分做如下操作：
记录已经扁平化链表的尾结点
第二个过程是从已经扁平化的链表中从后往前遍历 找到有子链的节点后 将其子链添加到当前尾结点的后面 同时更新尾结点
但这里没有考虑的是上述过程中子链中有结点仍带有子链的情况 
于是使用递归解决未考虑的情况
上述过程还需要注意第一个过程的对换和第二个过程中的拼接要注意根据题意更新结点child和prev
*/
class Solution 
{
    public:
        Node* flatten(Node* head) 
        {
            if(!head){
                return head;
            }
            Node* curr = head;
            while(curr->next || curr->child)                    //直到找到next和child均为空的结点
            {
                if(curr->child)                                 //如果一个结点的child不为空 则对换其的next和child
                {
                    std::swap(curr->child, curr->next);         //交换next链和child链        
                    curr->next->prev = curr;                    //更新next链头结点的prev                         
                    if(curr->child)                             //如果child不为空链 则将其prev清空
                    curr->child->prev = nullptr;
                }
                curr = curr->next;                              //向后遍历
            }
            Node *tail = curr;                                  //对已经扁平化的链表中child不为空的结点进行处理
            while(curr)
            {
                curr->child = Solution::flatten(curr->child);   //递归操作因为子链中的结点仍可能带有子链 将所有的嵌套子链扁平化
                if(curr->child)                                 //如果结点的child不为空则将其拼接到已经扁平化的链表后
                {
                    tail->next = curr->child;                   //child链拼接到当前扁平化链表后面
                    curr->child->prev = tail;                   //同时更新child链头结点prev
                    Node* cur = curr->child;                    //用于寻找child链的尾结点
                    while(cur->next)
                    {
                        cur = cur->next;
                    }
                    tail = cur;                                 //将扁平化链表的尾结点更新为child链的尾结点
                    curr->child = nullptr;                      //清空结点的child链    
                }                 
                curr = curr->prev;                              //向前遍历
            }
            return head;
        }
};
