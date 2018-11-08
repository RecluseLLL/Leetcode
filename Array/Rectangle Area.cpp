/*223. 矩形面积
在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。
每个矩形由其左下顶点和右上顶点坐标表示，如图所示。
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rectangle_area.png
示例:
输入: -3, 0, 3, 4, 0, -1, 9, 2
输出: 45
说明: 假设矩形面积不会超出 int 的范围。
*/

/*
需要判断两个矩形是否重叠
如果不重叠直接面积相加
重叠时面积相加后减去重叠部分面积
*/
class Solution {
public:
    bool isNonOverlap(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        return (G <= A || E >= C || H <= B || F >= D);
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        int area = (C - A) * (D - B) + (G - E) * (H - F);
        int width = min(G, C) - max(A, E);
        int height = min(D, H) - max(B, F);
        return isNonOverlap(A, B, C, D, E, F, G, H)? area : area - width * height;
    }
};
