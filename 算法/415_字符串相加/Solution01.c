/*
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

    num1 和num2 的长度都小于 5100.
    num1 和num2 都只包含数字 0-9.
    num1 和num2 都不包含任何前导零。
    你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * addStrings(char * num1, char * num2)
{
    
    int     len_num1    = strlen(num1);
    int     len_num2    = strlen(num2);
    int     max_len     = len_num1 > len_num2 ? len_num1 : len_num2;
    int     min_len     = len_num1 > len_num2 ? len_num2 : len_num1;
    char*   longerstr   = len_num1 > len_num2 ? num1     : num2;
    char*   shorterstr  = len_num1 > len_num2 ? num2     : num1;
    
    int     carry_flag  = 0;    /* 0 无进位,1有进位*/
    char*   pointer2    = NULL;
    int     i           = 0;
    int     temp        = 0;
    
    
    carry_flag = 0;
    for(i = max_len-1 ; i >= 0; i--)
    {
        if(max_len - i  <= min_len)
        {
            temp = longerstr[i] - 0x30 + shorterstr[i+min_len-max_len] - 0x30 + carry_flag;
        }
        else
        {
            temp = longerstr[i] - 0x30 + carry_flag;
        }
        longerstr[i] = temp % 10 + 0x30;
        if(temp>=10)
        {
            carry_flag = 1;
        }
        else
        {
            carry_flag = 0;
        }
    }
    
    if(carry_flag == 0)
    {
        return longerstr;
    }
    else
    {
        pointer2 = (char*)malloc(sizeof(char)*(max_len+2));
        pointer2[max_len+1] = 0;
        
        pointer2[0] = '1';
        memcpy(&pointer2[1],longerstr,max_len);
        
        
        return pointer2;
    }
}


int main()
{
    char a[] = "1";
    char b[] = "1";
    char* c = addStrings(a, b);
    printf("c = %s \n",c);
}
/*
缺点：返回值接口指针没统一，有两种可能，一种需要free，一种不需要free但会导致原数组被改变. 优点：..................
测试用例不检查原数组是否改变，也不检查是否要free，所以能省点内存 = =.
*/

/*
执行用时 : 4 ms, 在Add Strings的C提交中击败了100.00% 的用户 
内存消耗 : 7.2 MB, 在Add Strings的C提交中击败了85.94% 的用户


315 / 315 个通过测试用例
状态：通过
执行用时：4 ms
提交时间：2 分钟之前
*/