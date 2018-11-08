/*83. 删除排序链表中的重复元素
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:
输入: 1->1->2
输出: 1->2

示例 2:
输入: 1->1->2->3->3
输出: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head==NULL||head->next==NULL)
        {
            return head;
        }   
        struct ListNode *cur = head;              //试探结点
        while(cur->next)                          //试探第一个到倒数第二个结点 最终为尾节点时退出循环（确保cur->next->val有意义）
        {
            if(cur->val == cur->next->val)
            {
                cur->next = cur->next->next;      //删除cur的后继节点
                //cur应保持不变
            }
            else
            {
                cur = cur ->next;                 //更新cur
            }
        }
        return head;    
    }
};
