

char findTheDifference(char * s, char * t)
{
    char    ret_val =   0x00    ;
    int     i       =   0       ;
    
    while(s[i])
    {
        ret_val ^= s[i];
        i++;
    }
    
    i = 0;
    while(t[i])
    {
        ret_val ^= t[i];
        i++;
    }
    
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了82.67% 的用户
内存消耗 :7 MB, 在所有 C 提交中击败了71.05%的用户
*/