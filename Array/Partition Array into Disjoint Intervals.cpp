/*915. 分割数组
给定一个数组 A，将其划分为两个不相交（没有公共元素）的连续子数组 left 和 right， 使得：
left 中的每个元素都小于或等于 right 中的每个元素。
left 和 right 都是非空的。
left 要尽可能小。
在完成这样的分组后返回 left 的长度。可以保证存在这样的划分方法。
*/


/*
思路:right序列中的每一个值都不小于left序列中的最大值
index 记录left最后一个元素的下标 currmax为left序列中的最大值 maxval为当前遍历过的元素中的最大值 (预分割失败时更小currmax)
从第一个元素开始 当遇到不小于currmax的元素时，进行预分割 更新maxval为遍历元素 
在预分割状态下更新maxval
当遇到比currmax小的元素时，预分割失败 将currmax 更新为maxval
重复上述过程
*/

class Solution {
public:
    int partitionDisjoint(vector<int>& A) 
    {
        int len = A.size();
        if(!len || len == 1)
        {
            return len;
        }
        int i, index = 0;               // index为left最后一个元素的索引
        int currmax = A[0], maxval = A[0];  //currmax记录left序列的最大值 maxval记录当前遍历过的元素的最大值
        int prtn = 0;                       // 进行分割时置1
        for(i = 1; i < len; i++)
        {
            if(A[i] < currmax)
            {
                if(prtn)                    // 分割失败
                {
                    currmax = maxval;       //将left序列中的最大值更新为所有元素的最大值
                    prtn = 0;
                }
                index = i;
            }
            else                            // 遇到第一个不小于当前left序列中最大值的元素，进行预分割
            {
                if(!prtn) //进行分割
                {
                    maxval = A[i];          //更新当前遍历的所有元素的最大值
                    prtn = 1;
                }
                else                        //处于分割的状态
                {
                    if(A[i] > maxval)
                    {
                        maxval = A[i];      //更新当前遍历的所有元素的最大值
                    }
                    
                }
            }
        }
        return index + 1;
    }
};
