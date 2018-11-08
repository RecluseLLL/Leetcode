/*435.无重叠区间
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
注意:
可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

示例 1:
输入: [ [1,2], [2,3], [3,4], [1,3] ]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。

示例 2:
输入: [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。

示例 3:
输入: [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 /*
 当一个区间的start小于其前一个区间的end时 表明两个区间发生了重叠 这时需要移除其中一个 
 那么移除的区间应该是end较大的 而保留的区间应该是end较小的,这样可以尽量避免重叠的发生
 按照区间的start排序 使用prev始终记录前一个区间的end 初始化为第一个区间的end 然后开始遍历第二个区间到最后一个区间.
 如果当前遍历区间的start小于前一个区间的end 就表明发生了重叠 此时将prev更新为发生重叠的两个区间的end之中的较小值 
 这样可以尽量避免下一次重叠的发生 同时prev也模拟了一次移除操作
 cnt记录移除的次数 发生一次重叠就增加一次
 如果不发生重叠 将prev更新为当前遍历区间的end
 */
class Solution 
{
public:
    static bool compare(const Interval& a, const Interval& b)
    {
        if(a.start == b.start)
        {
            return a.end < b.end;
        }
        else return a.start < b.start;
    }
    int eraseOverlapIntervals(vector<Interval>& intervals) 
    {
        if(intervals.empty())
        {
            return 0;
        }
        int len = intervals.size(), cnt = 0;
        sort(intervals.begin(), intervals.end(), compare);
        int prev = intervals.begin()->end;
        for(int i = 1; i < len; i++)
        {
           if(prev > intervals[i].start)
           {
                prev = min(prev, intervals[i].end);
                cnt++;
           }
           else
           {
               prev = intervals[i].end;
           }
        }
        return cnt;
    }
};
