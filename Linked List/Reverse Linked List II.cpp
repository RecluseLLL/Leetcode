/*92.反转链表 II
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
*/
/*
找到第m个结点 同时适用prev记录其前趋结点 方便反转后将其连接到prev后面 当然如果需要反转链表的头结点为链表的头结点 则直接将反转后的链表的头结点作为链表的头结点
找到第n个结点 同时记录其后继结点（如果存在）方便其连接在反转链表后 而反转链表的尾结点就是 反转前传入链表的头结点 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        if(!head || !head->next || m == n)
        {
            return head;
        }
        ListNode *curr = head, *prev = nullptr, *tmphead, *temp = nullptr, *ret;
        int i = 1;
        while(i < m && curr)                            //找到第m个结点
        {
            prev = curr;                                //记录遍历结点的前趋结点
            curr = curr->next;
            i++;
        }
        tmphead = curr;                                 //需要反转的链表的头结点
        while(i < n && curr)                            //找到第n个结点
        {
            i++;
            curr = curr->next;
        }
        if(curr)                                        //如果curr未遍历完
        {
            temp = curr->next;                          //记录curr的后继结点（如果存在） 连接到反转过的链表的尾部
            curr->next = NULL;                          //将需要处理的链表尾结点的next置空
        }
        ret = helper(tmphead);                          //将需要反转的部分进行反转
        tmphead->next = temp;                           //反转前的头结点 反转后变成了尾结点 将第n个结点的后继结点连接到其后面
        if(!prev)return ret;                            //如果反转链表的头结点的前趋结点为空 直接将反转后的链表的头结点作为头结点返回
        prev->next = ret;                               //如果反转链表的头结点的前趋结点不为空将 反转后的链表连接到其后面
        return head;
    }
    static ListNode *helper(ListNode *head)             //辅助函数反转给定的链表
    {
        if(!head || !head->next)
        {
            return head;
        }
        else
        {
            ListNode *new_head = helper(head->next);           
            head->next->next = head;                                
            head->next = nullptr;                                  
            return new_head;
        }
    }
};