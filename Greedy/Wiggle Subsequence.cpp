/*376.摆动序列
如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。

例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。相反, [1,4,7,2,5] 和 [1,7,4,5,5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。

给定一个整数序列，返回作为摆动序列的最长子序列的长度。 通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。

示例 1:

输入: [1,7,4,9,2,5]
输出: 6 
解释: 整个序列均为摆动序列。
示例 2:

输入: [1,17,5,10,13,15,10,5,16,8]
输出: 7
解释: 这个序列包含几个长度为 7 摆动序列，其中一个可为[1,17,10,13,10,16,8]。
示例 3:

输入: [1,2,3,4,5,6,7,8,9]
输出: 2
*/
/*
摆动序列 即单调性交替发生变化的序列 不管一个单调序列的长度有多长 只将当前单调序列的最后一个元素添加到摆动序列中
长度为0、1、或者单调的长度为2的序列 摆动序列长度等于它们自身的长度
对于每个长度大于2的序列 摆动序列至少为1 首先将摆动序列长度 ret置1 然后开始向后遍历 找到第一个单调序列 并且将单调性用inc记录
继续遍历,如果当前序列的前一个序列递增并且此时遍历的序列开始递减 或者前一个序列递减并且此时遍历的序列开始递增 那么就遍历完当前这个单调序列 
不管其多长 只将摆动序列的长度加一 然后更新记录单调性的变量inc
重复上述过程 直到遍历完成
*/
class Solution 
{
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        int len = nums. size();
        if(len < 2)
        {
            return len;
        }
        int i, ret = 1, inc = -1;  
        //ret 记录摆动序列的长度 inc递增标志 置1表示序列递增 置0表示序列递减 
        for(i = 1; i < len && nums[i] == nums[i-1]; i++);
        if(i < len)
        {
            ret++;
            inc = nums[i] > nums[i-1];
            ++i;
        }
        while(i < len)
        {
            if((inc && nums[i] < nums[i-1]) || (!inc && nums[i] > nums[i-1]))
            {
                if(inc)
                {
                    while(nums[i] <= nums[i-1])
                    {
                        i++;
                    }
                }
                else
                {
                    while(nums[i] >= nums[i-1])
                    {
                        i++;
                    }
                     
                }
                ret++;
                inc ^= 1;
            }
            else
            {
                i++;
            }
        }
        return ret;
    }
};