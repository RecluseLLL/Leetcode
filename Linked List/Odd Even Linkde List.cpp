/*328.奇偶链表
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:
输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL

示例 2:
输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL

说明:
应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
*/
/*对于长度小于3的链表 直接返回其本身 
  对于长度不少于3的链表 构造快慢指针 快指针走两步 慢指针走一步 
  将快指针所指向的结点使用temp暂存 然后将其删除
  使用tmptail记录奇数结点构成的链表的尾结点
  再将暂存的快指针所指向的结点连接到当前奇数结点构成的链表的尾部然后更新奇数链表的尾结点
  将fast更新为slow开始下一次循环 
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
        ListNode* oddEvenList(ListNode* head) 
        {
            if(!head ||!head->next||!head->next->next)return head;
            ListNode *fast = head, *slow = head, *tmptail = head, *temp; // tmptail 记录已经处理好的奇数结点构成的链表的尾结点 temp记录每次需要处理的奇数结点
            while(slow->next && fast->next->next)
            {
                slow = slow->next;
                fast = fast->next->next;
                temp = fast;
                slow->next = fast->next;
                temp->next = tmptail->next;
                tmptail->next = temp;
                tmptail = temp;
                fast = slow;
            }
            return head;
        }
    
};