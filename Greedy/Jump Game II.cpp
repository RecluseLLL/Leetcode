/*45. 跳跃游戏 II
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
*/

/*
用最小的跳跃次数跳到末尾 每次肯定先尝试从当前位置开始跳跃 如果无法达到末尾 只能在自己可跳跃范围内寻找一个跳板 借助这个跳板到达更远的位置
cnt记录跳跃次数 pos表示当前的位置
首先在自己当前位置跳跃 如果可以到达末尾 退出循环 否则只能寻找跳板
在寻找的跳板中 借助reach为到达跳板后可到达的最远位置 在当前位置的跳跃范围中寻找跳板 然后将当前位置更新为跳板位置 
然后判断pos是否到达末尾
重复上述过程 
*/

class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int len = nums.size();
        int pos = 0;                                    //当前位置
        int cnt = 0;                                    //跳跃次数
        for(int i = 0; i < len - 1 && pos < len -1;)
        {
            cnt++;
            pos = nums[i] + i;                          //当前位置进行跳跃
            if(pos >= len - 1)                          //可以到达末尾
            {
                break;
            }
            else                                        //寻找跳板
            {
            int reach = 0;                              //跳跃到跳板后可以到达的最远位置
            for(int j = 1; j <= nums[i]; j++)
            {
                if(nums[i + j] + i + j >= reach)        //找到可以到达最远位置的跳板
                {
                    reach = nums[i+ j] + i + j;
                    pos = i + j;                        //更新pos
                }
            }
            i = pos;                                    //更新遍历所用变量                               
            }
        }
        return cnt;
    }
};