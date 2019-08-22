

bool strMatch(char* str1 , char* str2 , int len)
{
    bool    ret_val =   true    ;
    int     i       =   0       ;
    for(i=0;i<len;i++)
    {
        if(str1[i]!=str2[i])
        {
            ret_val = false;
            break;
        }
    }
    return ret_val;
}

int strStr( char*   haystack,
            char*   needle
          )
{
    int ret_val = 0                 ;
    int len1    = strlen(haystack)  ;
    int len2    = strlen(needle)    ;
    int i       = 0                 ;
    
    do
    {
        if(len2==0)
        {
            break;
        }
        ret_val = -1;
        if(  ( len1== 0    )
           ||( len1<  len2 )
        )
        {
            break;
        }
        if(len1==len2)
        {
            if(strMatch(haystack,needle,len2)==true)
            {
                ret_val = 0;
            }
            break;
        }
        else
        {
            for(i=0;i<=(len1-len2);i++)
            {
                if(haystack[i]==needle[0])
                {
                    if(strMatch(&haystack[i],needle,len2)==true)
                    {
                        ret_val = i;
                        break;
                    }
                }
            }
        break;
        }        
    }while(0);
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C 提交中击败了71.31% 的用户
内存消耗 :7.1 MB, 在所有 C 提交中击败了88.36%的用户
*/
