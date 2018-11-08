/*763.划分字母区间
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

示例 1:
输入: S = "ababcbacadefegdehijhklij"
输出: [9,7,8]

解释:
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
*/

/*
首先记录字符串中的每一个字母出现的最后位置
维护一个max_index变量为当前遍历过的子串的字母中最后出现位置的最大值 sublen记录每次划分的长度
然后开始遍历 如果遍历变量等于这个max_index进行一次划分 将划分子串长度清0 直至遍历完成
*/
class Solution 
{
public:
    vector<int> partitionLabels(string S) 
    {
        int len = S.size(), max_index = -1, sublen = 0;;
        vector<int>freq(26, -1), res;
        for(int i = 0; i < len; i++)
        {
            if(i > freq[S[i] - 'a'])
            {
                freq[S[i] - 'a'] = i;
            }
        }
        for(int i = 0; i < len; i++)
        {
            if(freq[S[i] - 'a'] > max_index)
            {
                max_index = freq[S[i] - 'a'];
            }
            sublen++;
            if(i == max_index)
            {
                res.push_back(sublen);
                sublen = 0;   
            }
        }
        return res;
    }
};