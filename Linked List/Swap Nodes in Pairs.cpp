/*24.两两交换链表中的结点
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
示例:
给定 1->2->3->4, 你应该返回 2->1->4->3.
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
        ListNode* swapPairs(ListNode* head) 
        {
            ListNode *curr = head, *prev = nullptr, *temp;          //curr为一对结点中的前者     
            while(curr && curr->next)
            {
                temp = curr->next;                                  //记录一对结点中的后者
                curr->next = curr->next->next;                      //删除一对结点中的后者
                if(curr == head)                                    //交换头两个结点
                {                          
                    temp->next = head;                              //将当前结点连接到删除结点后
                    head = temp;                                    //将头结点更新为删除的结点
                    prev = head->next;                              //将前趋结点更新为头结点的后继结点
                }
                else
                {                            
                    temp->next = prev->next;                        //将temp插入到前一对结点的后面
                    prev->next = temp;
                    prev = curr;                                    //curr变成了一对结点中的后者 将prev更新为curr
                }
                curr = prev->next;                                  //更新curr
            }
            return head;
        }
};
