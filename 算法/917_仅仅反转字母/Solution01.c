/*
给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
示例 1：
输入："ab-cd"
输出："dc-ba"
示例 2：
输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"
示例 3：
输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"
提示：
    S.length <= 100
    33 <= S[i].ASCIIcode <= 122 
    S 中不包含 \ or "
*/

/*
* 方法1:双指针(数组索引)
*/
bool isLetter(char ch)
{
    bool ret_val = false;
    if(  ((ch>='a')&&(ch<='z'))
       ||((ch>='A')&&(ch<='Z'))
    )
    {
        ret_val = true;
    }
    
    return ret_val;
}

char* reverseOnlyLetters(char * S)
{
    
    int     str_len  =  strlen(S)   ;
    int     head     =  0           ;
    int     tail     =  str_len -1  ;
    char    temp     =  0           ;
    bool    ret_val1 =  false       ;
    bool    ret_val2 =  false       ;
    
    while(head < tail)
    {
        ret_val1 = isLetter(S[head]);
        ret_val2 = isLetter(S[tail]);
        if( ret_val1 && ret_val2 )
        {
            temp    = S[head]   ;
            S[head] = S[tail]   ;
            S[tail] = temp      ;
            head++;
            tail--;
            continue;
        }
        
        if(!ret_val1)
        {
            head++;
        }
        if(!ret_val2)
        {
            tail--;
        }
    }
    return S;
}

/*
* 方法2:双指针(指针索引)
*/
bool isLetter(char ch)
{
    bool ret_val = false;
    if(  ((ch>='a')&&(ch<='z'))
       ||((ch>='A')&&(ch<='Z'))
    )
    {
        ret_val = true;
    }
    
    return ret_val;
}

char* reverseOnlyLetters(char * S)
{
    
    int     str_len  = strlen(S)            ;
    char*   head     = S                    ;
    char*   tail     = &S[str_len -1]       ;
    char    temp     = 0                    ;
    bool    ret_val1 = false                ;
    bool    ret_val2 = false                ;
    
    while(head < tail)
    {
        ret_val1 = isLetter(*head);
        ret_val2 = isLetter(*tail);   
        if( ret_val1 && ret_val2 )
        {
            temp    = *head ;
            *head   = *tail ;
            *tail   = temp  ;
            head++  ;
            tail--  ;
            continue;
        }
        
        if(!ret_val1)
        {
            head++;
        }
        
        if(!ret_val2)
        {
            tail--;
        }
    }
    return S;
}


/*
方法1:
执行用时 :4 ms, 在所有 C 提交中击败了94.83%的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了75.00%的用户
*/
/*
方法2:
执行用时 :4 ms, 在所有 C 提交中击败了94.83%的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了72.22%的用户
*/