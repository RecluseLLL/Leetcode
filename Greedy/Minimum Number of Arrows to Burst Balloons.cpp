/*452.用最少数量的箭引爆气球
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。开始坐标总是小于结束坐标。平面内最多存在104个气球。
一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。
Example:

输入:
[[10,16], [2,8], [1,6], [7,12]]
输出:
2

解释:
对于该样例，我们可以在x = 6（射爆[2,8],[1,6]两个气球）和 x = 11（射爆另外两个气球）。
*/

/*
如果元素个数小于2 直接返回元素个数
类似于活动选择问题 按照结束坐标排序
先将prev初始化为第一个元素的结束坐标  箭数初始化为1
然后从对于第二个元素开始遍历 直到找到一个元素的开始坐标大于prev 此时箭数加一 并且将prev更新为这个元素的结束坐标 
重复上述过程直至遍历完成
*/
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points)
    {
        int len = points.size();
        if(len < 2) return len;
        sort(points.begin(), points.end(), 
        [](const pair<int, int>& a, const pair<int, int>& b){return a.second < b.second;});
        int prev = points[0].second, arrows = 1;
        for(int i = 1; i < len; i++)
        {
            if(points[i].first > prev)
            {
                arrows++;
                prev = points[i].second;
            }
        }
        return arrows;
    }
};
