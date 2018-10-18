/*70.爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。

示例 1：
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶

示例 2：
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
*/

/*矩阵快速幂求解*/

class Solution 
{
    public:
        int climbStairs(int n) 
        {
            if(n <= 2)
            {
                return n;
            }
            vector<vector<int>>res(2, vector<int>(2));
            res[0][0] = res[1][1] = 1; 
            res[0][1] = res[1][0] = 0;
            QuickPower(res, n - 2);
            return res[0][0] * 2 + res[0][1];
        }
        void QuickPower(vector<vector<int>>&res, int n)
        {
            vector<vector<int>>base(2, vector<int>(2));
            base[0][0] = base[1][0] = base[0][1] = 1;
            base[1][1] = 0;
            while(n)
            {
                if(n & 1)
                {
                    res = Multiply(res, base);
                }
                base = Multiply(base, base);
                n >>= 1;
            }
        }
        vector<vector<int>> Multiply(vector<vector<int>>a, vector<vector<int>>b)    //矩阵相乘
        {   
            vector<vector<int>>ans(2, vector<int>(2));
            int i, j, k;
            for(i = 0; i < 2; i++)
            {
                for(j = 0; j < 2; j++)
                {
                    for(k = 0; k < 2; k++)
                    {
                        ans[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
            return ans;
        }
};