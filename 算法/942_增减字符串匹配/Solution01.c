

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char * S, int* returnSize)
{
    int  str_len = strlen(S);
    int* ret_val = (int*)malloc((str_len+1)*sizeof(int));
    int  i       = 0;
    int  num_i   = 0;
    int  num_d   = 0;

    ret_val[0] = 0;
    for (i = 0; i < str_len; i++)
    {
        switch (S[i])
        {
            case 'I':
                ret_val[i+1] = ++num_i;
            break;
            case 'D':
                ret_val[i+1] = --num_d;
            break;
            default:
            break;
        }
    }
    str_len++;
    if(num_d<0)
    {
        num_d = -num_d;
        for (i = 0; i < str_len; i++)
        {
            ret_val[i] += num_d;
        }
    }
    
    *returnSize = str_len;
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :104 ms, 在所有 C 提交中击败了9.57% 的用户
内存消耗 :12.8 MB, 在所有 C 提交中击败了89.01%的用户
*/