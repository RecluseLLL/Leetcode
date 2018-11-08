/*725.分隔链表
给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。
每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。
这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。
返回一个符合上述规则的链表的列表。

举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]

示例 1：
输入: 
root = [1, 2, 3], k = 5
输出: [[1],[2],[3],[],[]]
解释:
输入输出各部分都应该是链表，而不是数组。
例如, 输入的结点 root 的 val= 1, root.next.val = 2, \root.next.next.val = 3, 且 root.next.next.next = null。
第一个输出 output[0] 是 output[0].val = 1, output[0].next = null。
最后一个元素 output[4] 为 null, 它代表了最后一个部分为空链表。

示例 2：
输入: 
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
输出: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
解释:
输入被分成了几个连续的部分，并且每部分的长度相差不超过1.前面部分的长度大于等于后面部分的长度。
 

提示:
root 的长度范围： [0, 1000].
输入的每个节点的大小范围：[0, 999].
k 的取值范围： [1, 50].

*/

/*
首先每组链表的长度为链表的总长度len / k 如果 len % k 不为0 则对前len % k组的链表的长度+1
还可以使用三目运算符将一部分情况进行合并 
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) 
    {
        vector<ListNode*>res;
        int i;
        if(!root)                                            //如果链表为空 直接添加k个NULL
        {
            for(i = 0; i < k; i++)
            {
                res.push_back(root);
            }
            return res;
        }
        int len = 0;
        ListNode* curr = root;
        while(curr)                                          //计算链表的长度
        {
            len++;
            curr = curr->next;
        }
        int each_len = len / k, surplus = len % k, cnt;      //平均长度和多余的结点个数 
        curr = root;
        ListNode *tmphead = root, *temp;                    
        for(i = 1; i <= surplus; i++)                        //对前len % k组的链表 每一组长度 + 1 这一部分和下面的部分有重叠的部分 可以使得surplus自减 然后使用三目运算符进行合并
        {
            cnt = 1;
            tmphead = curr;
            while(cnt < each_len + 1)
            {
                cnt++;
                curr = curr->next;            
            }
            temp = curr->next;                               //开始分隔 暂存分隔结点的下一个结点 作为下次迭代的起始结点
            curr->next = nullptr;                            //分隔
            res.push_back(tmphead);
            curr = temp;                                     //更新下次开始迭代的结点
        }
        for(; i <= k; i++)                                   //每一组链表长度为len / k 如果走完 在后面添加NULL 直到添加了k组
        {
            if(!curr)
            {
                res.push_back(nullptr);
            }
            else
            {
                tmphead =curr;
                cnt = 1;
                while(cnt < each_len)
                {
                    curr = curr->next;
                    cnt++;
                }
                temp = curr->next;
                curr->next = nullptr;
                res.push_back(tmphead);
                curr = temp;
            }
        }
        return res;
    }
};
