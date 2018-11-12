/*11. 盛最多水的容器
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。
*/
/*
先将边界设为数组的开始位置和结束位置
根据短板原理 先计算当前能盛水的量 与当前最大盛水量area对比进行更新
然后从较短的边界处向中间位置靠拢
重复该过程 直到左右边界的距离为1
*/
class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int len = height.size();
        int l = 0, r = len - 1;
        int area = 0;
        while(l < r)
        {
            area = max(area, (r - l) * min(height[l], height[r]));
            if(height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return area;
    }
};