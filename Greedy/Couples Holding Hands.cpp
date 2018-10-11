/*
N 对情侣坐在连续排列的 2N 个座位上，想要牵到对方的手。 计算最少交换座位的次数，以便每对情侣可以并肩坐在一起。 一次交换可选择任意两人，让他们站起来交换座位。
人和座位用 0 到 2N-1 的整数表示，情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2N-2, 2N-1)。
这些情侣的初始座位  row[i] 是由最初始坐在第 i 个座位上的人决定的。
*/

/*
贪心算法 逐个迭代每一对相邻的座位 对于任意的相邻座位 如果前面的座位不能其伴侣的手 则去寻找其伴侣 然后将其伴侣更换到与之相邻
*/
class Solution {
public:
    int minSwapsCouples(vector<int>& row) 
    {
        int len = row.size();
        int i;
        int cnt = 0;                                                                //记录交换次数
        for(i = 0; i < len - 1; i += 2)
        {
            int num = row[i] % 2? row[i] - 1 : row[i] + 1;                          //获得其伴侣的编号
            if(row[i + 1] != num)                   
            {
                cnt++;
                vector<int>::iterator iter = std::find(row.begin(),row.end(),num);  //找到其伴侣的位置的迭代器
                int index = std::distance(row.begin(), iter);                       //获取伴侣的座位下标
                std::swap(row[index], row[i + 1]);                                  //交换伴侣到与其相邻的座位
            }
        }
        return cnt;
    }
};