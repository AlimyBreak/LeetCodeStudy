
/*
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
在 S 上反复执行重复项删除操作，直到无法继续删除。
在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
示例：
输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
提示：
    1 <= S.length <= 20000
    S 仅由小写英文字母组成.
*/



/*
* 实现1:原地模拟出栈入栈操作
*/
char* removeDuplicates(char * S)
{
    int str_len     =   strlen(S) ;
    int i           =   0         ;
    int valid_index =   0         ;
                                  
    for(i = 0; i < str_len ; i++)
    {
        if(valid_index == 0)    /* 边界情况,一定是入栈*/
        {
            S[valid_index] = S[i]   ;
            valid_index++           ;
            continue                ;
        }
        
        if(S[i] == S[valid_index-1])    /* 碰到情侣就杀死*/
        {
            valid_index--           ;
            S[valid_index] = '\0'   ;
        }
        else                            /* 碰到单身狗就存好*/
        {
            S[valid_index] = S[i]   ;
            valid_index++           ;
            continue                ;
        }
    }
    
    S[valid_index] = '\0';
    return S;
}


/*
* 实现2:原地模拟出栈入栈操作(优化循环)
*/
char* removeDuplicates(char * S)
{
    int i           =   0         ;
    int valid_index =   0         ;
                                  
    while(S[i] != '\0')
    {
        if(valid_index == 0)    /* 边界情况,一定是入栈*/
        {
            S[valid_index] = S[i]   ;
            valid_index++           ;
        }
        else
        {
            if(S[i] == S[valid_index-1])    /* 碰到情侣就杀死*/
            {
                valid_index--           ;
                S[valid_index] = '\0'   ;
            }
            else                            /* 碰到单身狗就存好*/
            {
                S[valid_index] = S[i]   ;
                valid_index++           ;
            }
        }
        i++;
    }
    
    S[valid_index] = '\0';
    return S;
}


/*
实现1:
执行用时 :12 ms, 在所有 C 提交中击败了81.25%的用户
内存消耗 :8 MB, 在所有 C 提交中击败了100.00%的用户
*/

/*
实现2:
执行用时 :4 ms, 在所有 C 提交中击败了97.92%的用户
内存消耗 :8 MB, 在所有 C 提交中击败了100.00%的用户
*/
