/*
给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
说明：不要使用任何内置的库函数，如sqrt()。
示例 1：
    输入：16
    输出：True
示例 2：
    输入：14
    输出：False
*/


/* 
    基本原理：奇数数列的累加和就是完全平方数.
*/
bool isPerfectSquare(int num)
{
    bool    ret_val =   false   ;
    int     i       =   1       ;
    do
    {
        if(num <=0)
        {
            break;
        }
        
        while(num>0)
        {
            num = num - i;
            if(num==0)
            {
                ret_val = true;
                break;
            }
            i = i + 2;
        }
        break;
    }while(0);
    return ret_val;
}

/*
执行用时 :4 ms, 在所有 C 提交中击败了94.56%的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了5.71%的用户
*/
