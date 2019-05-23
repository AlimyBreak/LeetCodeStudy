/*
给定两个二进制字符串，返回他们的和（用二进制表示）。
输入为非空字符串且只包含数字 1 和 0。
示例 1
输入 a = 11, b = 1
输出 100
示例 2
输入 a = 1010, b = 1011
输出 10101
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char * a, char * b){
    
    int     len_a       =   strlen(a)   ;
    int     len_b       =   strlen(b)                       ;
    int     max_len     =   len_a > len_b ? len_a : len_b   ;
    int     min_len     =   len_a > len_b ? len_b : len_a   ;
    char*   longerstr   =   len_a > len_b ? a     : b       ;
    char*   shorterstr  =   len_a > len_b ? b     : a       ;
    int     carry_flag  =   0                               ;    /* 0 无进位,1有进位*/
    char*   ret_pointer =   NULL                            ;
    int     i           =   0                               ;
    int     temp        =   0                               ;
    
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
        longerstr[i] = temp % 2 + 0x30;
        if(temp>=2)
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
        ret_pointer = (char*)malloc(sizeof(char)*(max_len+2));
        //memset(ret_pointer,0,sizeof(char)*(max_len+2));
        ret_pointer[max_len+1] = 0x00;
        ret_pointer[0] = '1';
        //for(i = 1; i <= max_len ; i++)
        //{
        //    ret_pointer[i] = longerstr[i-1];
        //}
        memcpy(&ret_pointer[1],longerstr,max_len*sizoof(char));
        return ret_pointer;
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char* a = "1";
    char* b = "111";
    char* c = addBinary(a,b);
    printf("a+b = %s\n",c);
    
    free(c);
    c = NULL;
    
    getchar();
    return 0;
}


/*
执行用时 : 0 ms, 在Add Binary的C提交中击败了100.00% 的用户
内存消耗 : 6.9 MB, 在Add Binary的C提交中击败了35.19% 的用户
294 / 294 个通过测试用例
状态：通过
执行用时：0 ms
提交时间：0 分钟之前
*/