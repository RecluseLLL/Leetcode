/*19. 删除链表的倒数第N个节点
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：
给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：
给定的 n 保证是有效的。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
        {
            struct ListNode *temp = head,*prevDeNode = head;
            int length = 1; 
            int i;
            while(temp->next)               //找到尾结点和链表的长度 length始终和结点的保持个数一致 因此找到尾节点时退出循环
            {
                temp = temp->next;
                length++;
            }
            if(n == length)
            {
                return head->next;
            }
            for(i = 1; i < length - n; i++) //找到目标结点的前驱结点 第n-k个结点
            {
                prevDeNode = prevDeNode->next;
            }
            prevDeNode->next = prevDeNode->next->next;
            return head;
        }    
    }
};