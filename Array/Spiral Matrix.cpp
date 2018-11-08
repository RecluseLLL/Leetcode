/*54. 螺旋矩阵
给定一个包含 row x n 个元素的矩阵（row 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
示例 1:
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]

示例 2:
输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

该题代码同时适用于螺旋矩阵II II是I的一部分
*/


/*
这道题类似于蛇形填数 每次走一圈 圈数用circle表示 从0开始  
而一圈分为四个部分 右->下->左->上
右阶段 列递增 每次循环到列下标为col - circle - 1的位置
上阶段 行递增 每次循环到行下标为row - circle - 1的位置
左阶段 列递减 每次循环到列下标为circle的位置
右阶段 行递减 每次循环到行下标为circle的位置
在提交第一次后发现只适合行数 列数为偶数的情况
在行数或者列数中的一者为奇数时便会发生错误
此时最后一圈不会完成四个阶段
如果行数为奇数 最后一圈完成右阶段 无法完成下阶段 那么这时便用行数进行判断 完成右阶段如果行数不合法 即大于等于row - ciccle 直接退出循环 
如果列数为奇数 最后一圈完成右阶段和下阶段 无法完成左阶段 这时便用列数判断 完成下阶段如果列数不合法 即小于circle 直接退出循环
列数和行数同时为奇数时 取决于两者谁更大 如果一样大只完成右阶段
实际上 特殊情况的退出情况也可以根据cnt的值进行判断 但耗时会变长
*/

class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int> >& rowatrix)
    {
        vector<int>res;
        int row = rowatrix.size();
        if(!row)return res;
        int col = rowatrix[0].size();
        int total = row * col,cnt = 0;
        int i = 0, j = 0;                          // 遍历行列使用
        int circle = 0;
        while(cnt < total)
        {
            while(j < col - circle )               //右阶段
            {
                cnt++;
                res.push_back(rowatrix[i][j]);
                j++;
            }
            i++;j--;                               //复位
            if(!(i < row - circle))//if(cnt >= total)
            {
                break;
            }
            while(i < row - circle )               //下阶段
            {
                cnt++;
                res.push_back(rowatrix[i][j]);
                i++;
            }
            i--;j--;                              //复位
            if(!(j >= circle))//if(cnt >= total)
            {
                break;
            }
            while(j >= circle )                  //左阶段
            {
                cnt++;
                res.push_back(rowatrix[i][j]);
                j--;

            }
            i--;j++;                            //复位
            while(i > circle)                   //下阶段
            {
                cnt++;
                res.push_back(rowatrix[i][j]);
                i--;
            }
            i++;j++;                           //复位
            circle++;
       }
       return res;
    }

};
