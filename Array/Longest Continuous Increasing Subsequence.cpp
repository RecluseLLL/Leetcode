/*674. 最长连续递增序列
给定一个未经排序的整数数组，找到最长且连续的的递增序列。

示例 1:
输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 

示例 2:
输入: [2,2,2,2,2]
输出: 1
解释: 最长连续递增序列是 [2], 长度为1。
注意：数组长度不会超过10000。
*/

/*
最长连续递增序列的长度为局部递增序列中长度最长的
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int len = nums.size();
        if(!len || len == 1) return len;
        int i,  length= 1, temp = 1;        //temp记录局部最长连续递增序列 length记录整个数组的最长递增序列的长度
        for(i = 0; i < len - 1; i++)
        {
            if(nums[i + 1] <= nums[i])      //单调递增性增到破坏 
            {
                temp = 1;                   //长度置为1
                continue;                   //开始下次循环
            }
            temp++;                         //局部单调递增序列的长度增加
            length = std::max(length, temp);//length为局部单调递增序列中长度最长的
        }
        return length;
    }
};
