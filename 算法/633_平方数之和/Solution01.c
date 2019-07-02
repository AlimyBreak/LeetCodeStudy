/*
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。

示例1:

输入: 5
输出: True
解释: 1 * 1 + 2 * 2 = 5
示例2:
输入: 3
输出: False
*/

bool isSquare(int c)
{
    bool    ret_val = false;
    int     temp    = 0;
    do
    {
        if( c < 0 )
        {
            ret_val = false;
            break;
        }
        
        if(  ( c == 0 )
           ||( c == 1 )
        )
        {
            ret_val = true;
            break;
        }
        temp = (int)(sqrtf(c));
        if(c == temp*temp )
        {
            ret_val = true;
        }
        else
        {
            ret_val = false;    
        }
        break;
    }while(0);
    
    return ret_val;
}

/*方法1:常规遍历法*/
bool judgeSquareSum(int c)
{
    
    bool ret_val = false    ;
    int  i       = 0        ;
    int  temp    = 0        ;
    
    do
    {
        if(c<0)
        {
            ret_val = false;
            break;
        }
        
        if( c < 3)
        {
            ret_val = true;
            break;
        }
        
        while(  (temp    >= 0     )
              &&(ret_val == false )
              &&(i       <  46341 ) /*防止平方溢出*/
        )
        {
            temp = c - i*i;
            ret_val = isSquare(temp);
            i++;
        }
        break;
    }while(0);
    return ret_val;
}

/*
执行用时 :12 ms, 在所有 C 提交中击败了26.58%的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了69.70%的用户
*/

/*方法2:上下限逼近法*/
bool judgeSquareSum(int c)
{
    bool ret_val = false;
    int  left    = 0;
    int  right   = (int)(sqrtf(c));
    
    do
    {
        if(c<0)
        {
            ret_val = false;
            break;
        }
        else if(c<3)
        {
            ret_val = true;
            break;
        }
        else
        {
            while(  (left    <= right)
                  &&(ret_val == false)
            )
            {
                if(left*left > c - right*right ) /*这里不要用 x*x +　y*y = z ,防止左边相加溢出*/
                {
                    right --;
                }
                else if(left*left  == c - right*right)/*这里不要用 x*x +　y*y = z ,防止左边相加溢出*/
                {
                    ret_val = true;
                }
                else
                {
                    left++;
                }
            }
        }
    }while(0);
    
    return ret_val;
}

/*
执行用时 :4 ms, 在所有 C 提交中击败了96.20%的用户
内存消耗 :6.9 MB, 在所有 C 提交中击败了69.70%的用户
*/
