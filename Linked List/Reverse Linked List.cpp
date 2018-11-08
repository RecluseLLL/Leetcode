/*206. 反转链表
反转一个单链表。

示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
*/

/*
如果链表的长度不少于2 先对头结点之后的链表进行反转 然后将头结点插在其后继结点结点之后 
此时其后继结点已经位于反转的末尾 然后将新的尾结点 即原来的头结点next置空
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution 
{
    public:
        ListNode* reverseList(ListNode* head)
        {
            if(!head || !head->next)
            {
                return head;
            }
            else
            {
                ListNode *new_head = reverseList(head->next);           //新的头结点为处理完头结点后的链表的头结点
                head->next->next = head;                                //处理完后原来头结点的后继结点为尾结点 再将头结点插入到其后面 使头结点成为尾结点
                head->next = nullptr;                                   //将尾结点的next置空
                return new_head;
            }
        }
};
