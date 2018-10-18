/*203.移除链表元素
删除链表中等于给定值 val 的所有节点。

示例:
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/

/*prev记录试探结点curr的前趋结点 找到值为val的结点后如果该结点有前趋结点（不是头结点）则将其前趋结点的next中存储该结点的后继结点 删除该结点 然后试探结点curr更新为prev的后继结点
如果该结点没有前趋结点 则将该结点的后继结点更新为头结点 然后将curr更新为它的后继结点
每一找到该结点 更新prev为试探结点 然后试探结点向后遍历
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
        ListNode* removeElements(ListNode* head, int val) 
        {
            ListNode *curr = head, *prev = nullptr;
            while(curr)
            {
                if(curr->val == val)
                {
                    if(!prev)                                       //无前趋结点
                    {
                        head = curr->next;
                        curr = curr->next;
                    }
                    else                                            //存在前趋结点
                    {
                        prev->next = curr->next;
                        curr = prev->next;
                    }
                   
                }
                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
            return head;
        }
};