/*784.字母大小写全排列
给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。
示例:
输入: S = "a1b2"
输出: ["a1b2", "a1B2", "A1b2", "A1B2"]

输入: S = "3z4"
输出: ["3z4", "3Z4"]

输入: S = "12345"
输出: ["12345"]
注意：

S 的长度不超过12。
S 仅由数字和字母组成。
*/

/*
对于一个数字返回它自身
对于一个字母 应该小写 再返回大写
那么以小写字母为基准 先返回它自身 然后再返回它的大写形式
而对于大写字母把它转化成小写字母进行处理
辅助函数用了实现这个功能 
如果到达原始字符串末尾 就是其中的一种情况 把临时字符存储到结果中
否则遇到数字 直接添加到临时字符串中 
遇到字母 转化成小写
然后先把自己转化添加到临时字符串中
然后把其后面的字符串交给辅助函数处理
然后把临时子串串中从该字母之后的字符串删除
然后把大写形式添加到临时字符串
将其后面的字符串交由辅助函数处理
然后把刚才添加到临时字符串的内容全部删除
*/


class Solution 
{
public:
        vector<string> letterCasePermutation(string S) 
        {
            vector<string>res;
            int len = S.size();
            string temp;
            helper(res, 0, len, temp, S);
            return res;
        }
        static void helper(vector<string>& res, int index, int len, string& temp, string& origin)
        {
            if(index == len)
            {
                res.push_back(temp);
            }
            else
            {
                if(isdigit(origin[index]))
                {
                    temp.append(1, origin[index]);
                    helper(res, index + 1, len, temp, origin);
                }
                else
                {
                    if(isupper(origin[index]))
                    {
                        origin[index] = tolower(origin[index]);
                    }
                    temp.append(1, origin[index]);
                    helper(res, index+1, len, temp, origin);
                    temp.erase(temp.begin() + index, temp.end());
                    temp.append(1, toupper(origin[index]));
                    helper(res, index+1, len, temp, origin);
                    temp.erase(temp.begin() + index, temp.end());
                }
            }
            return;
        }
};