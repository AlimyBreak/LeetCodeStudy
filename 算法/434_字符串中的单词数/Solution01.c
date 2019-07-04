
/*
统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
请注意，你可以假定字符串里不包括任何不可打印的字符。
示例:
输入: "Hello, my name is John"
输出: 5
*/

bool isChar(char c)
{
    if(//   (c>='A'&&c<='Z')
       // ||(c>='a'&&c<='z')
       // ||(c=='\'')
       // ||(c=='-')
        c!=' '
    )
    {
        return true;
    }
    {
        return false;
    } 
}

/*看清楚关于"单词"的神定义,被玩了*/
int countSegments(char * s)
{
    int  count      = 0;
    int  str_len    = strlen(s);    
    int  i          = 1;
    
    if(str_len==0)
    {
        count = 0;
    }
    else
    {
        while(1)
        {
            if(i>=str_len)
            {
                break;
            }
            if(  (isChar( s[i]   )==false    )
              && (isChar( s[i-1] )==true     )
            )
            {
                count++;
            }
            i++;
        }
        if(isChar(s[str_len-1]))
        {
            count++;
        }
    }
    return count;
}


/*
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了38.10%的用户
*/

