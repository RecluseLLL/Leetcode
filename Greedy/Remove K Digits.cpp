/*402.移掉K位数字
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:
num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。

示例 1 :
输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。

示例 2 :
输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
示例 3 :

输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。
*/


/*
去除数字后尽量保证每一个的数字最小
从第一个元素 寻找从当前位置i到当前位置i+ k 的最小值 然后记录最小值的索引 添加到结果字符串中 然后去掉最小值之前的所有元素 即k做相应的变化 k减小的值为最小值所在位置与当前位置的差值
直到k是0或者结果字符串的长度为原字符串的长度 len - k时退出循环
但退出循环后可能出现 i < len 即 结果字符串的长度 小于 len-k 那么将退出循环时的位置以及其后面的所有元素加到结果字符串中
如果结果字符串中以0开头 则去掉该元素 直到结果字符串第一个元素不为0
如果去掉以0开头的情况后 结果字符串为空 则返回0
*/

class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        int len = num.size();
        if(k == len) return "0";
        int i, j;
        int index = 0;                                             //记录保留数字的索引
        char minval;                                               //记录每一次从当前位置i到 i+k的最小值 作为保留数字
        string res;                                                //结果字符串
        int length = len - k;                                      //结果字符串的长度
        for(i = 0; i < len && k > 0 && res.size() != length; )
        {
            minval = 74;                                           //初始化为9的ASCII码 + 1
            for(j = i; j <= i + k && j < len; j++)
            {
                if(num[j] < minval)
                {
                    minval = num[j];
                    index = j;
                }
            }
            res.append(1, minval);
            k = k - (index - i);
            i = index + 1;
        }
        if(i < len && res.size() < length)
        {
            for(; i < len; i++)
            {
                res.append(1, num[i]);
            }
        }
        while(res[0] == '0')                                       //去掉开头为0的情况
        {
            res.erase(res.begin());
        }
        if(!res.size())return "0";                                 //去掉开头为0的情况后结果字符串空 返回0
        return res;
    }
};
