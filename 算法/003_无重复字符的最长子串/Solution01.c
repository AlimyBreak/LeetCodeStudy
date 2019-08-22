/*****
若target在 s[start,end)中没有重复的就返回-1,
若有重复的就返回重复数据所在的索引值.
*****/
int exsit_double(   char*   s       ,   
                    int     start   ,
                    int     end     ,
                    char    target
                )
{
    int ret_val = -1    ;
    int i       = 0     ;
    
    
    for(i = start;i < end;i++)
    {
        if(target==s[i])
        {
            ret_val = i;
            break;
        }
    }
    return ret_val;
}

int lengthOfLongestSubstring(char * s)
{

    int ind_front   = 0   ;
    int ind_end     = 1   ;
    int ret_val     = 0   ;
    int temp        = 0   ;

    if(s[0])    /* 原始数据长度长度不为0*/
    {
        while(s[ind_end])
        {
            temp = exsit_double(s,ind_front,ind_end,s[ind_end]);
            if(temp==-1)
            {
                ind_end++;
            }
            else
            {
                ret_val     =   ret_val >= (ind_end-ind_front) ? ret_val : (ind_end-ind_front)          ;
                ind_front   =   temp + 1                                                                ;
                ind_end++                                                                               ;
            }
        }
        ret_val = ret_val >= (ind_end-ind_front) ? ret_val : (ind_end-ind_front) ;
    }
    return ret_val;
}


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C 提交中击败了79.84% 的用户
内存消耗 :7.2 MB, 在所有 C 提交中击败了75.45%的用户
*/