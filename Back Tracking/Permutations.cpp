/*46.全排列
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

/*对于每一个序列 将每个元素都作为序列的第一个元素 然后序列后面的元素进行处理 
使用一个临时数组 当其长度达到len时就为全排列的一种可能
第i次将序列的第一个元素与第i个元素交换 因为第i次应该将第i个元素作为序列的开头 将序列的第一个元素添加到临时数组中后 对其后面的序列进行处理
然后将临时数组清空 重复上述操作
*/
class Solution 
{
    public:
        vector<vector<int>> permute(vector<int>& nums) 
        {
            vector<vector<int>>res;
            int len = nums.size();
            vector<int>temp;
            helper(res, 0, len, temp, nums);
            return res;
        }
        static void helper(vector<vector<int>>&res, int index, int len,vector<int>&temp, vector<int>nums)
        {
            if(index == len)
            {
                res.push_back(temp);
            }
            int i;
            for(i = index; i < len; i++)
            {
                std::swap(nums[index], nums[i]);
                temp.push_back(nums[index]);
                helper(res, index + 1, len, temp, nums);
                temp.erase(temp.begin() + index, temp.end());                                                                                
            }
            return;
        }
};
