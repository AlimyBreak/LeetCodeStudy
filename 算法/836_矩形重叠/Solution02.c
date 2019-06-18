
/*
矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。
如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。
给出两个矩形，判断它们是否重叠并返回结果。

示例 1：
输入：rec1 = [0,0,2,2], rec2 = [1,1,3,3]
输出：true
示例 2：
输入：rec1 = [0,0,1,1], rec2 = [1,0,2,1]
输出：false
说明：
    两个矩形 rec1 和 rec2 都以含有四个整数的列表的形式给出。
    矩形中的所有坐标都处于 -10^9 和 10^9 之间。
*/


/*
* 基本思路:  x轴有交集 且 y 轴 有交集
* 难点:   
*    1.线段l1-[x1,x2] 和 线段l2-[x3,x4] 如何判断有无交集.
*    2.进行符号判断时要进行防溢出处理.
*/
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size)
{   
    int flag1 = rec2[0] - rec1[2]; //(x3-x2);
    int flag2 = rec2[2] - rec1[0]; //(x4-x1);
    int flag3 = rec2[1] - rec1[3]; //(y3-y2);
    int flag4 = rec2[3] - rec1[1]; //(y4-y1);
    
    if(flag1 == 0 || flag2 == 0 || flag3 == 0 || flag4 == 0) /* 可以直接判断没有交集*/
    {
        return false;
    }
    else
    {
        /* 防溢出,只取符号*/
        flag1 = flag1 > 0 ? 1:-1;
        flag2 = flag2 > 0 ? 1:-1;    
        flag3 = flag3 > 0 ? 1:-1;    
        flag4 = flag4 > 0 ? 1:-1;    
    }
    return (flag1*flag2<0 && flag3*flag4 < 0 );
}


/*
执行用时 :4 ms, 在所有 C 提交中击败了93.94%的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了69.57%的用户
*/
