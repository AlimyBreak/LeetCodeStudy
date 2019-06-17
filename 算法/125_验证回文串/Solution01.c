
/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:
输入: "race a car"
输出: false
*/

int isNum(char ch)
{
    return ((ch >= '0') && (ch <= '9')) ? 1 : 0;
}

int isChar(char ch)
{
    return (((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z'))) ? 1 : 0;
}

bool isPalindrome(char * s)
{
    
    bool    ret_val = true          ; /* init */
    int     len     = strlen(s)     ;
    char*   head    = s             ;
    char*   tail    = &s[len-1]     ;
    char    ch_h    = 0             ;
    char    ch_t    = 0             ;
    int     type_h  = 0             ;
    int     type_t  = 0             ;
    
    while(head < tail)
    {
        
        ch_h    =   (*head)                         ;
        ch_t    =   (*tail)                         ;
        type_h  =   isNum(ch_h) + isChar(ch_h) * 2  ;
        type_t  =   isNum(ch_t) + isChar(ch_t) * 2  ;
        
        if(  (type_h != 0)
           &&(type_t != 0)
        )
        {
            if (type_h != type_t)
            {
                ret_val = false;
                break;
            }
            /* 这里可以省略
            else if(type_h==0x01)
            {
                if(ch_h == ch_t)
                {
                    head++;
                    tail--;
                    continue;
                }
                else
                {
                    ret_val = false;
                    break;
                }
                
            }*/
            else 
            {
                if((ch_h|32) == (ch_t|32))
                {
                    head++;
                    tail--;
                    continue;
                }
                else
                {
                    ret_val = false;
                    break;
                }
            }
        }
        else if(type_h == 0)    /* head指向非需要比较类型*/
        {
            head++;
        }
        else if(type_t==0)  /* tail指向非需要比较类型*/
        {
            tail--;
        }
    }
    
    
    return ret_val;

}

/*
执行用时 :4 ms, 在所有C提交中击败了96.32%的用户
内存消耗 :7.4 MB, 在所有C提交中击败了58.22%的用户

476 / 476 个通过测试用例
状态：通过
执行用时：4 ms
提交时间：0 分钟之前
*/

