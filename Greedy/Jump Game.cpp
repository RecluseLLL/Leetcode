/*55. 跳跃游戏
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。
示例 1:
输入: [2,3,1,1,4]
输出: true
解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
*/

/*reach为可到达位置 依次遍历 每次都要尽量让reach更大*/

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int len = nums.size();
        if(!len)return false;
        int reach = 0;                  //reach为可到达位置
        for(int i = 0; i < len; i++)
        {
            if(i > reach)               //当前遍历位置大于可到达位置 必定无法到达末尾
            {
                return false;
            }
            if(nums[i] + i > reach)     //如果当前位置可以跳转到更远 更新可到达位置
            {
                reach = nums[i] + i;
            }
        }
        if(reach >= len - 1)            //可到达位置可以到达末尾
        {
            return true;
        }
        return false;
    }
};