

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
    
    bool    ret_val     = true          ; /* init */
    int     valid_len   = 0             ;
    int     i           = 0             ;

    i         = 0;
    valid_len = 0;
    while(s[i] != '\0')
    {
        if(   isNum ( s[i] ) 
           || isChar( s[i] )
        )
        {
            s[valid_len] = s[i] | 32;
            valid_len ++;
        }
        i++;
    }
    
    i = 0;
    while( i < valid_len-1 )
    {
        if(s[i] != s[valid_len-1])
        {
            ret_val = false;
            break;
        }
        i++;
        valid_len--;
    }
    return ret_val;
}

/*
执行用时 :4 ms, 在所有C提交中击败了96.32%的用户
内存消耗 :7.5 MB, 在所有C提交中击败了30.92%的用户
*/