/*42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png
上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/

/*将数组的开始与结束位置设为左边界lb 右边界rb
根据短板效应 从边界较小的位置开始向中间靠拢
l为左边界较小时的遍历变量 r是右边界较小时的遍历变量 每次遍历的盛水量为边界处的值减去遍历处的值
然后更新边界 重复该过程 
*/
class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int res = 0, len = height.size();
        int lb = 0, rb = len - 1;
        int l = lb + 1, r = rb - 1;
        while(lb < rb)
        {
            if (height[lb] < height[rb])
            {
                if(height[l] < height[lb])
                {
                    res += height[lb] - height[l];
                }
                else
                {
                    lb = l;
                }
                l++;
            }
            else
            {
                if(height[r] < height[rb])
                {
                    res += height[rb] - height[r];
                }
                else
                {
                    rb = r;
                }
                r--;
            }
        }
        return res;
    }
};