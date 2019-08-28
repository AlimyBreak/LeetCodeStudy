char* defangIPaddr(char* address)
{
    int     str_len     =   0       ;
    int     dot_count   =   0       ;
    int     i           =   0       ;
    int     j           =   0       ;
    char*   ret_val     =   NULL    ;
    
    while(address[i])
    {
        str_len++;
        if(address[i]=='.')
        {
            dot_count++;
        }
        i++;
    }
    
    ret_val = (char*)malloc(str_len+2*dot_count+1);
    ret_val[str_len+2*dot_count] = 0;
    i = 0;
    for(j=0;j<str_len;j++)
    {
        if(address[j]!='.')
        {
            ret_val[i++] = address[j];
        }
        else
        {
            ret_val[i++] = '[';
            ret_val[i++] = '.';
            ret_val[i++] = ']';
        }
    }
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了100.00%的用户
*/