/*885.螺旋矩阵III
在 R 行 C 列的矩阵上，我们从 (r0, c0) 面朝东面开始
这里，网格的西北角位于第一行第一列，网格的东南角位于最后一行最后一列。
现在，我们以顺时针按螺旋状行走，访问此网格中的每个位置。
每当我们移动到网格的边界之外时，我们会继续在网格之外行走（但稍后可能会返回到网格边界）。
最终，我们到过网格的所有 R * C 个空间。
按照访问顺序返回表示网格位置的坐标列表。
示例:
https://leetcode-cn.com/problems/spiral-matrix-iii/description/
*/

/*
对于每一圈circle 先向右走circle*2 - 1次 再向下走circle*2 - 1次 再向左走 2*circle次 再向上走2*circle次
每次移动 如果位置合法 即在矩阵中 则添加该位置
*/

class Solution 
{
    public:
        vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) 
        {
            int row = r0, col = c0;
            int cnt = 0, i, circle = 1;
            vector<vector<int>>res(R * C, vector<int>(2, 0));
            res[cnt][0] = r0;
            res[cnt][1] = c0;
            while(cnt != R * C - 1)
            {
                for(i = 1; i <= circle * 2 - 1; i++)
                {
                    col++;
                    if(judge(row, col, R, C))
                    {
                        res[++cnt][0] = row;
                        res[cnt][1] = col;
                    }
                }
                for(i = 1; i <= circle * 2 - 1; i++)
                {
                    row++;
                    if(judge(row, col, R, C))
                    {
                        res[++cnt][0] = row;
                        res[cnt][1] = col;
                    }
                }
                for(i = 1; i <= circle * 2; i++ )
                {
                    col--;
                   if(judge(row, col, R, C))
                    {
                        res[++cnt][0] = row;
                        res[cnt][1] = col;
                    }
                }
                for(i = 1; i <= circle * 2; i++)
                {
                    row--;
                    if(judge(row, col, R, C))
                    {
                        res[++cnt][0] = row;
                        res[cnt][1] = col;
                    }
                }
                circle++;
            }
            return res;
        }
        bool judge(int i, int j, int R, int C)                  //判断位置是否合法 
        {
            return (i >= 0 && i < R && j >= 0 && j < C);
        }        
};
