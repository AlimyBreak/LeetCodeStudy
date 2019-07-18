

char * removeOuterParentheses(char * S)
{
    int     str_len         = strlen(S);   
    char*   ret_val         = (char*)malloc(sizeof(char)*str_len);
    int     valid_len       = 0;
    char*   stack_s         = (char*)malloc(sizeof(char)*str_len);
    int     stack_val_count = 0;
    int     i               = 0;
    int     level           = 0;
    
    //memset(ret_val,0,sizeof(char)*str_len);
    for(i = 0; i < str_len ; i++)
    {
        if(stack_val_count==0)
        {
            level = 1;
            stack_s[stack_val_count] = S[i]; /*sc.push(S.at(i));*/
            stack_val_count++;
        }
        else
        {
            if(S[i]=='(')
            {
                level ++;
                stack_s[stack_val_count++]= S[i]; /*sc.push(S.at(i));*/
                if(level > 1)
                {
                    ret_val[valid_len++] = S[i];
                }
                
            }
            else
            {
                //sc.pop();
                stack_val_count--;
                if(level-- > 1)
                {
                    ret_val[valid_len++] = S[i];
                }
                
            }
        }
    }
    
    ret_val[valid_len] = 0;
    free(stack_s);
    stack_s = NULL;
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗 :7.3 MB, 在所有 C 提交中击败了14.29%的用户
*/