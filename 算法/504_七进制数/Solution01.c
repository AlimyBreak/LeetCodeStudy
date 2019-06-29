/*
给定一个整数，将其转化为7进制，并以字符串形式输出。
示例 1:
输入: 100
输出: "202"
示例 2:
输入: -7
输出: "-10"
注意: 输入范围是 [-1e7, 1e7] 。
*/

/* reserse str[start~end],close area*/
void str_reverse(char* str , int start , int end)
{
    char c = 0;
    
    while(start<end)
    {
        c           = str[start];
        str[start]  = str[end];
        str[end]    = c;
        start++;
        end--;
    }
}


char* convertToBase7(int num)
{
    char* ret_val = (char*)malloc(20);  /* 20个字节足够了吧*/
    int   ind     = 0;
    int   temp    = num;
    
    
    do
    {
        if(ret_val)
        {
            memset(ret_val,0,20);   /*清零*/
        }
        else
        {
            break;/* 空间没申请成功*/
        }
        
        if(num<0)
        {
            ret_val[ind] = '-'      ;
            temp         = -temp    ;
            ind++                   ;
        }
        do
        {
            ret_val[ind] = temp % 7 + 0x30  ;
            ind++                           ;
            temp /= 7                       ;
        }while(temp!=0);
        
        if(num < 0)
        {
            str_reverse(ret_val,1,ind-1);
        }
        else
        {
            str_reverse(ret_val,0,ind-1);
        }
        break;
    }while(0);
        
    return ret_val;
}

/*
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了59.38%的用户
*/

