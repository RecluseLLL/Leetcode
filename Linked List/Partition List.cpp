/*86. 分隔链表
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
你应当保留两个分区中每个节点的初始相对位置。
*/
/*找到第一个值大于等于x的结点 记录其前趋结点为目标结点tail 然后继续遍历 记录试探结点的前趋结点prev 遇到值小于x的结点 先将其用temp暂存 然后删除 再将它插入到先前找到的目标结点后面 然后将其更新为目标结点 然后将curr更新为prev的后继结点 继续遍历
如果目标结点为nullptr 即第一个结点的值就大于等于x 则遇到值小于x的结点后 先将其删除 然后将现有链表连接到它后面 更新它为头结点 然后将它更新为目标结点 
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
        ListNode* partition(ListNode* head, int x) 
        {
            if(!head || !head->next)return head;
            ListNode *prev = nullptr, *curr = head, *tail = nullptr, *temp;
            while(curr && curr->val < x)                                    //找到第一个值大于等于x的结点 记录其前趋结点目标结点
            {                                               
                tail = curr;
                curr = curr->next;
            }                                                                                   
            while(curr)                                                     
            {
                if(curr->val < x)                                           //遇到值小于x的结点 将其插入到目标结点后
                {
                    temp = curr;                                            //暂存该结点
                    prev->next = curr->next;                                //删除
                    if(!tail)                                               //目标结点为空 链表的头结点的值就不小于x
                    {
                        temp->next = head;                                  //将现有链表连接到该结点后
                        head = temp;                                        //更新该结点为头结点
                        tail = temp;                                        //更新该结点为尾结点
                    }
                    else
                    {
                        temp->next = tail->next;                            //插入到目标结点tail后
                        tail->next = temp;
                        tail = temp;                                        //更新目标结点tail
                    }
                    curr = prev->next;                                      //更新curr为prev的后继结点
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
